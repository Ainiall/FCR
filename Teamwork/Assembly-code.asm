.386
.model flat, C

.code

; Complete the procedure
IsValidAssembly PROC
push ebp
mov ebp, esp ; prólogo
push edx
push ebx
push ecx
mov ecx,[ebp+16]   ;ecx=c
mov ebx,[ebp+12]	;ebx=b
mov edx,[ebp+8]		;edx=a
mov eax,4261412864
and edx,eax        ;edx= mascara 7 primenros bits
mov eax,33554431
and ebx,eax		;ebx=mascara de 25 ultimos bits
or edx,ebx		;edx=suma de mascaras
mov eax,8192	
and ecx,eax		;ecx=mascarra del bit 13
mov eax,512
and edx,eax		;edx=bit 9 de la suma de mascaras anterior
shr edx,9
shr ecx,13
cmp ecx,edx
je consecuente
mov eax,0
jmp siguiente
consecuente:
mov eax,1
siguiente:
pop ecx
pop ebx
pop edx
pop ebp
ret
IsValidAssembly ENDP

END