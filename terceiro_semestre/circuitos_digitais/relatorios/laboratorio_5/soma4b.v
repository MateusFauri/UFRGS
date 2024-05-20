module soma3b (
input	a0,
input	b0,
input	a1,
input	b1,
input	a2,
input	b2,
input	a3,
input	b3,
input   sub,
output	s0,
output	s1,
output	s2,
output	s3,
output  s4);

    wire fio1, fio2,fio3;
    wire fiob0, fiob1, fiob2, fiob3;

    xor(fiob0, b0, sub);
    xor(fiob1, b1, sub);
    xor(fiob2, b2, sub);
    xor(fiob3, b3, sub);

    full_adder bit_0(   .a(a0),
                        .b(fiob0),
                        .cin(sub),
                        .s(s0),
                        .cout(fio1));
	
    full_adder bit_1(   .a(a1),
                        .b(fiob1),
                        .cin(fio1),
                        .s(s1),
                        .cout(fio2) );
	
    full_adder bit_2(	.a(a2), 
						.b(fiob2), 
						.cin(fio2),
						.s(s2),
						.cout(fio3) );

	full_adder bit_3(	.a(a3), 
						.b(fiob3), 
						.cin(fio3),
						.s(s3),
						.cout(s4) );

endmodule

