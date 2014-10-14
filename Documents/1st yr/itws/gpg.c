Aim: Ritika(hello@info) sends a secret msg to angie(angie@info)


2046  gpg --homedir ~/ritika --export --armor hello@info > ritika.pub//making hello@info's key public..stored in ritika.pub
 2047  gpg --homedir ~/angie --export --armor angie123@info > angie.pub//" " " angie@info " "...stored in angie.pub
 2050  gpg --homedir ~/ritika --armor --import angie.pub// importing angie's public key to my keyring
 2050  gpg --homedir ~/angie --armor --import ritika.pub//" " " ritika's to angie's keyring




 2071  vim sec.txt//secret msg
 2072 gpg --homedir ~/ritika --armor --output letter.sign --sign sec.txt//sign msg using ritika's private key..stored in letter.sign
 2075  gpg --homedir ~/angie --encrypt --armor --recipient angie letter.sign//encrypt txt using angie's public key

 2076  ls lett*
 2077  gpg --homedir ~/angie --output news.txt --decrypt letter.sign.asc//angie decrypts msg using her own private key
 2078  cat news.txt
 2080  gpg --homedir ~/ritika  --output info.txt --decrypt news.txt//angie verifies signature using ritika's public key
 2081  cat info.txt
 2082  history

