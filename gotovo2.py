
table=[[12,4,6,2,10,5,11,9,14,8,13,7,0,3,15,1],
      [6,8,2,3,9,10,5,12,1,14,4,7,11,13,0,15],
      [11,3,5,8,2,15,10,13,14,1,7,4,12,9,6,0],
      [12,8,2,1,13,4,15,6,7,0,10,5,3,14,9,11],
      [7,15,5,10,8,1,6,13,0,9,3,14,11,4,2,12],
      [5,13,15,6,9,2,12,10,11,7,8,1,4,3,14,0],
      [8,14,2,5,6,9,1,12,15,4,11,0,13,10,3,7],
      [1,7,14,13,0,5,8,3,4,15,10,6,9,12,11,2]]
lll=(input("input the key"))
key=lll[:8]
k0=lll[8:16]
k1=lll[16:24]
k2=lll[24:32]
k3=lll[32:40]
k4=lll[40:48]
k5=lll[48:56]
k6=lll[56:64]
key=int(key,16)
k0=int(k0,16)
k1=int(k1,16)
k2=int(k2,16)
k3=int(k3,16)
k4=int(k4,16)
k5=int(k5,16)
k6=int(k6,16)
K=[key,k0,k1,k2,k3,k4,k5,k6,key,k0,k1,k2,k3,k4,k5,k6,key,k0,k1,k2,k3,k4,k5,k6,k6,k5,k4,k3,k2,k1,k0,key]
a=input("enter the input data1")
a=int(a,16)
b=input("enter the input data2")
b=int(b,16)
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
