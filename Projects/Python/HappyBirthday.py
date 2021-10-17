import time
line = "============================="

print(line)
name = input("Halo, Nama kamu siapa: ")
print(line)
time.sleep(3)

print("ohhh ini", name, "yaa")
print(line)
time.sleep(3)

print("Halo", name, "Kenalin aku program yang dibuat Mifth")
time.sleep(2)
print("Hope u like it !")
time.sleep(3)
print(line)

birth = input("Btw, hari ini lagi ulang tahun ya? yes/no: ")
while birth != "yes" :
    birth = input("Halah boong ! aku tanya lagi. Hari ini lagi ulang tahun ya? yes/no: ")
print(line)
time.sleep(2)
print("'I feel so lucky to have u as my friend. Hope ur birthday is a special as u're.\nMay all of ur dreams come true. Thanks for being such a great friend.'")
print(line)
time.sleep(5)

banyak = int(input("Mau di ucapin berapa kali? "))
time.sleep(3)
while banyak <= 0 :
    banyak = int(input("Seriusss ! Mau di ucapin berapa kali? "))
for i in range (banyak) :
    print("HAPPY BIRTHDAY,", name, "!")

while True:
  pass





