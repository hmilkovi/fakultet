*-----------------------------------------------------------
* Program Number: 2
* Written by    : Hrvoje Milkoviæ
* Date Created  : 12.10.2013
* Description   : Zadatak iz ASM
*-----------------------------------------------------------
START	ORG	$1000


	MOVE #14,D0
	LEA tekst,A1
	TRAP #15


	MOVE #2,D0
	LEA unos1,A1
	TRAP #15


	MOVE #51,D0
	TRAP #15


	MOVE #53,D0
	MOVE.L #80,D2
	LEA unos2,A6
	TRAP #15


	MOVE #14,D0
	LEA unos2,A6
	TRAP #15
	

	MOVE #14,D0
	LEA novired,A1
	TRAP #15


	MOVE #14,D0
	LEA tekst1,A1
	TRAP #15


	MOVE.B #4,D0
	TRAP #15
	
	MOVE D1,D7
	
	LEA unos1,A6
	MOVEA A6,A0
	MOVE.B (A6),D4


	MOVE #14,D0
	LEA novired,A1
	TRAP #15

	MOVE #14,D0
	LEA tekst2,A1
	TRAP #15
	

	JMP razmak
loop	CMP D6,D7
	BGE DALJE


	MOVE D6,D1


	MOVE.B #15,D0
	MOVE.B #10,D2
	TRAP #15

	MOVE #14,D0
	LEA razmak1,A1
	TRAP #15

	ADD #1,D5

DALJE	CMP #46,D4
	BEQ kraj

	MOVE #$0,D6
	ADD #1, A0
	MOVE.B (A0),D4
	JMP razmak

while1	ADD #1, A0
	MOVE.B D4,D3
	MOVE.B (A0),D4

	
	MULS #10,D6
	SUB.B #$30,D3
	ADD D3,D6


razmak	CMP #32,D4
	BEQ loop

	CMP #46,D4
	BEQ loop
	BNE while1

kraj	MOVE #14,D0
	LEA novired,A1
	TRAP #15

	MOVE #14,D0
	LEA tekst3,A1
	TRAP #15

	MOVE D5,D1
	MOVE.B #15,D0
	MOVE.B #10,D2
	TRAP #15


	MOVE.B	#9,D0
	TRAP	#15


tekst	DC.B 'Unesite naziv datoteke:',$D,$A,0
tekst1	DC.B 'Unesite broj:',$D,$A,0
tekst2	DC.B 'Brojevi veci od unesenog broja: ',$D,$A,0
tekst3	DC.B 'Broj brojeva: ',$D,$A,0
razmak1	DC.B ' '
novired DC.B $D,$A,0
unos1	DS.B 80
unos2	DS.B 80

	END START
*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~8~
