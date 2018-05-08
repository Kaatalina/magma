global i
global K
K = []
def fillkey():
	K=[0xffeeddcc,0xbbaa9988,0x77665544,0x33221100,0xf0f1f2f3,0xf4f5f6f7,0xf8f9fafb,0xfcfdfeff,0xffeeddcc,0xbbaa9988,0x77665544,0x33221100,0xf0f1f2f3,0xf4f5f6f7,0xf8f9fafb,0xfcfdfeff,0xffeeddcc,0xbbaa9988,0x77665544,0x33221100,0xf0f1f2f3,0xf4f5f6f7,0xf8f9fafb,0xfcfdfeff,0xfcfdfeff,0xf8f9fafb,0xf0f1f2f3,0x33221100,0x77665544,0xbbaa9988,0xffeeddcc]

def getkey(i):
	if (mode == '1'):
		x=K[i]
	else:
		x=K[(31-i)]

def fest(a,b,i):
	k1=i
	getkey(i)

a=0xfedcba98
b=0x76543210
print("%x %x" % (a, b))
print("for encryption -enter 1,for decryption 2")
mode=input();
if (mode == '1'):
	print("you have chosen the encryption mode")
else:
	print("you have chosen the descryptoin mode")
for i in range(32):

	fest(a,b,i)

print("%x %x" % (a,b))
