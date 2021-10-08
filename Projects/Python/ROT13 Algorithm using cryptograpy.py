# This is the program for ROT13 Algorithm using Cryptography in python 

def rot13(sentence):
    d = {}
    for ascii_code in (65, 97):
        for alphabet_index in range(26):
            d[chr(ascii_code + alphabet_index)] = \
                        chr(ascii_code + (alphabet_index + 13) % 26)
    return ''.join([d.get(letter, letter) for letter in sentence])
print(rot13('Pnrfnepvcure? V zhpucersrePnrfnefnynq!'))  