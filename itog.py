
table=[[12,4,6,2,10,5,11,9,14,8,13,7,0,3,15,1],
      [6,8,2,3,9,10,5,12,1,14,4,7,11,13,0,15],
      [11,3,5,8,2,15,10,13,14,1,7,4,12,9,6,0],
      [12,8,2,1,13,4,15,6,7,0,10,5,3,14,9,11],
      [7,15,5,10,8,1,6,13,0,9,3,14,11,4,2,12],
      [5,13,15,6,9,2,12,10,11,7,8,1,4,3,14,0],
      [8,14,2,5,6,9,1,12,15,4,11,0,13,10,3,7],
      [1,7,14,13,0,5,8,3,4,15,10,6,9,12,11,2]]
K=[0xffeeddcc,0xbbaa9988,0x77665544,0x33221100,0xf0f1f2f3,0xf4f5f6f7,0xf8f9fafb,0xfcfdfeff,
  0xffeeddcc,0xbbaa9988,0x77665544,0x33221100,0xf0f1f2f3,0xf4f5f6f7,0xf8f9fafb,0xfcfdfeff,
  0xffeeddcc,0xbbaa9988,0x77665544,0x33221100,0xf0f1f2f3,0xf4f5f6f7,0xf8f9fafb,0xfcfdfeff,
  0xfcfdfeff,0xf8f9fafb,0xf4f5f6f7,0xf0f1f2f3,0x33221100,0x77665544,0xbbaa9988,0xffeeddcc]
a=0xfedcba98
b=0x76543210
print(" %x %x " % (a,b))
print("for encryption -enter 1,for decryption 2")
mode=input();
if (mode == '1'):
	print("you have chosen the encryption mode")
else:
	print("you have chosen the descryptoin mode")
for i in range(32):
	k1=i
	if (mode == '1'):
		x=K[i]
	else:
		x=K[(31-i)]
	p=(b+x)%2**32
	for k in range(8):
		aa=((p&(0xf<<4*k))>>4*k)
		o=0x10**k
		t=table[k][aa]
		kk=aa*o
		t1=t*o
		p=p-kk
		p=p|t1
	p=p<<11|p>>21
	p=p&0xffffffff
	c=b
	a=p^a
	if (k1!=31):
		b=a
		a=c
print("%x %x" % (a,b))
