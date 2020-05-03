import socket

CONST_PORT = 9998;
CONST_HOST_NAME = ''
CONST_AMOUNT_PLAYERS = 2
CONST_ZERO = 0

def get_byte_messange(str):
    bytes = bytearray(str, 'utf-8')
    return len(bytes).to_bytes(2, 'little') + bytes + CONST_ZERO.to_bytes(2, 'little')

def send_all(set_players, state, pack = ''):
    for conn, addr in set_players:
        if state == 'waiting_conn':
            conn.send(get_byte_messange('Waiting for players...'))
        elif state == 'start':
            conn.send(get_byte_messange('The game has started'))
        elif state == 'waiting_turn':
            conn.send(get_byte_messange('Waiting for turn other player...'))
        elif state == 'pack':
            conn.send(get_byte_messange('Pack:' + str(pack)))

def send_directly(player, state):
    conn, addr = player
    if state == 'turn':
        conn.send(get_byte_messange('Waiting for your turn...'))

def get_pack(player):
    conn, addr = player
    pack = ''
    while True:
        pack += conn.recv(1024)
        if not pack:
            break
    return pack

def run_server():
    sock = socket.socket()
    sock.bind((CONST_HOST_NAME, CONST_PORT))
    sock.listen(CONST_AMOUNT_PLAYERS)
    set_players = set()
    for i in range(CONST_AMOUNT_PLAYERS):
        conn, addr = sock.accept()
        set_players.add((conn, addr))
        send_all(set_players, 'waiting_conn')
        print(i + 1, '/', CONST_AMOUNT_PLAYERS, ' connected: ', addr);

    send_all(set_players, 'start')

    while True:
        for player in set_players:
            send_directly(player, 'turn')
            send_all(set_players - set(player), 'waiting_turn')
            pack = get_pack(player)
            send_all(set_players - set(player), 'pack', pack);


if __name__ == '__main__':
    run_server();
