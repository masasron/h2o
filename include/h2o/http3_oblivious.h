/*
 * Declarations for HTTP/3 Proxy-Oblivious support
 */
#ifndef h2o__http3_oblivious_h
#define h2o__http3_oblivious_h

/* Use OpenSSL HPKE API instead of hpke-wrap */
#include <openssl/evp.h>
#include <openssl/hpke.h>
#include <openssl/err.h>

/**
 * Flag indicating if Proxy-Oblivious HPKE unwrap is enabled (via config)
 */
extern int have_proxy_obliv_key;
/**
 * Private key for HPKE unwrapping (EVP_PKEY format)
 */
extern EVP_PKEY *proxy_obliv_priv;

/**
 * Initializes the HPKE receiver context and loads the private key from a Base64URL-encoded file.
 * Must be called once at startup before handling any CONNECT requests.
 */
void init_proxy_oblivious(const char *priv_b64_path);

#endif /* h2o__http3_oblivious_h */