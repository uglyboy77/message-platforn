# 🔐 Message Encryption with AES-256 (C++ & OpenSSL)
This project demonstrates a simplified implementation of message encryption using AES-256 in C++, powered by the OpenSSL library. It is inspired by the encryption techniques employed by leading technology companies to secure user data.<br>
📌 <b>Overview</b><br>
The application accepts user input via the console and encrypts it using the AES-256-CBC algorithm. The encrypted output is displayed in hexadecimal format, representing a randomized mix of numbers and letters. This format helps obscure the original message and makes it difficult for third parties to interpret without the correct decryption key.<br>
🔧 <b>How It Works</b><br>
- A 256-bit encryption key and a 128-bit initialization vector (IV) are securely generated using OpenSSL's RAND_bytes() function.
- The user's message is encrypted using the AES-CBC mode via AES_cbc_encrypt().
- The resulting ciphertext is converted to hexadecimal for display.<br>
⚠️ <b>Note</b><br>
This implementation is intended for educational purposes and does not include:
- Secure key storage or key exchange mechanisms<Br>
- Padding schemes (e.g., PKCS#7) for block alignment<Br>
- Authentication (e.g., HMAC or AES-GCM)<Br>
- Error handling or input validation<Br>
For production-grade encryption, additional security measures must be implemented to ensure data integrity, confidentiality, and authenticity.


