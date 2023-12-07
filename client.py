import socket
import random
import time

def diffie_hellman(p, g):
    b = random.randint(2, p - 2)
    B = pow(g, b, p)
    return b, B

def calculate_secret_key(A, b, p):
    return pow(A, b, p)

def main():
    host = '127.0.0.1'
    port = 12345

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))

    p = 23  # Common prime number
    g = 5   # Primitive root of p

    b, B = diffie_hellman(p, g)
    time.sleep(2)
    print("Client's private key (b):", b)
    time.sleep(2)
    print("Client's public key (B):", B)

    client_socket.send(str(B).encode())
    server_public_key = int(client_socket.recv(1024).decode())
    time.sleep(2)
    print("Server's public key:", server_public_key)

    secret_key = calculate_secret_key(server_public_key, b, p)
    time.sleep(2)
    print("Secret key calculated at client:", secret_key)

    client_socket.close()

if __name__ == '__main__':
    main()
