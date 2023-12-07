import socket
import random
import time

def diffie_hellman(p, g):
    a = random.randint(2, p - 2)
    A = pow(g, a, p)
    return a, A

def calculate_secret_key(B, a, p):
    return pow(B, a, p)

def main():
    host = '127.0.0.1'
    port = 12345

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(1)

    print("Server waiting for connection...")
    conn, addr = server_socket.accept()
    print("Connection from: " + str(addr))

    p = 23  # Common prime number
    g = 5   # Primitive root of p

    b, B = diffie_hellman(p, g)
    print("Server's private key (b):", b)
    time.sleep(2)
    print("Server's public key (B):", B)
    time.sleep(2)

    conn.send(str(B).encode())
    client_public_key = int(conn.recv(1024).decode())
    time.sleep(2)
    print("Client's public key:", client_public_key)

    secret_key = calculate_secret_key(client_public_key, b, p)
    time.sleep(2)
    print("Secret key calculated at server:", secret_key)

    conn.close()

if __name__ == '__main__':
    main()
