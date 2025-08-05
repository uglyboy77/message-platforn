#include <iostream>
#include <string>
#include <openssl/evp.h>
#include <openssl/err.h>

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    ctx = EVP_CIPHER_CTX_new();
    if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();
    if (!EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) handleErrors();
    ciphertext_len = len;
    if (!EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int main() {
    ERR_load_crypto_strings();
    OpenSSL_add_all_algorithms();

    unsigned char key[32] = {0}; // Use a simple zeroed key for testing
    unsigned char iv[16] = {0};

    std::string message;
    std::cout << "Enter your message: ";
    std::getline(std::cin, message);

    unsigned char ciphertext[128];
    int ciphertext_len = encrypt((unsigned char *)message.c_str(), message.length(), key, iv, ciphertext);

    std::cout << "Encrypted message: ";
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    std::cout << std::endl;

    EVP_cleanup();
    ERR_free_strings();
    return 0;
}