from pyDes import des, PAD_PKCS5
import binascii

def encrypt_des(message, key):
    des_cipher = des(key, padmode=PAD_PKCS5)
    encrypted_text = des_cipher.encrypt(message)
    return encrypted_text

def decrypt_des(encrypted_text, key):
    des_cipher = des(key, padmode=PAD_PKCS5)
    decrypted_text = des_cipher.decrypt(encrypted_text)
    return decrypted_text

def main():
    choice = input("Enter 'E' for encryption or 'D' for decryption: ").upper()
    
    if choice == 'E':
        plaintext = input("Enter the text to encrypt: ").encode()
        key = input("Enter the key (8 bytes): ").encode()
        encrypted_text = encrypt_des(plaintext, key)
        print("Encrypted:", binascii.hexlify(encrypted_text))
    
    elif choice == 'D':
        ciphertext = bytes.fromhex(input("Enter the ciphertext to decrypt (in hex): "))
        key = input("Enter the key (8 bytes): ").encode()
        decrypted_text = decrypt_des(ciphertext, key)
        print("Decrypted:", decrypted_text.decode())
    
    else:
        print("Invalid choice. Please enter 'E' for encryption or 'D' for decryption.")

if __name__ == "__main__":
    main()
