module soma3b (
input	a0,
input	b0,
input	a1,
input	b1,
input	a2,
input	b2,
output	s0,
output	s1,
output	s2,
output	s3);

    wire joaquim, manuel;

    half_adder meu_half_adder_querido(	.a(a0), 
										.b(b0), 
										.s(s0),
										.cout(joaquim));
	
	
    full_adder picole(	.a(b1), 
						.b(a1), 
						.cin(joaquim),
						.s(s1),
						.cout(manuel));

	full_adder bit_3(	.a(b2), 
						.b(a2), 
						.cin(manuel),
						.s(s2),
						.cout(s3));

endmodule

