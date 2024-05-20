module soma2b (
input	a0,
input	b0,
input	a1,
input	b1,
output	s0,
output	s1,
output	s2);

    wire joaquim;

    half_adder meu_half_adder_querido(	.a(a0), 
										.b(b0), 
										.s(s0),
										.cout(joaquim));
	
	
    full_adder picole(	.a(b1), 
						.b(a1), 
						.cin(joaquim),
						.s(s1),
						.cout(s2));

endmodule

