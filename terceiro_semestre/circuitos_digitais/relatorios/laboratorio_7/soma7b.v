module soma7b (
input	[6:0] a,
input	[6:0] b,
output	[6:0] s);

    wire joaquim, manuel, c2to3, c3to4, c4to5, c5to6, c6to7;

    half_adder meu_half_adder_querido(	.a(a[0]), 
					.b(b[0]), 
					.s(s[0]),
					.cout(joaquim));
	
	
    full_adder picole(	.a(b[1]), 
			.b(a[1]), 
			.cin(joaquim),
			.s(s[1]),
			.cout(manuel));

	full_adder bit_2(	.a(b[2]), 
				.b(a[2]), 
				.cin(manuel),
				.s(s[2]),
				.cout(c2to3));
						
	full_adder bit_3(	.a(b[3]), 
				.b(a[3]), 
				.cin(c2to3),
				.s(s[3]),
				.cout(c3to4));

	full_adder bit_4(	.a(b[4]), 
				.b(a[4]), 
				.cin(c3to4),
				.s(s[4]),
				.cout(c4to5));


	full_adder bit_5(	.a(b[5]), 
				.b(a[5]), 
				.cin(c4to5),
				.s(s[5]),
				.cout(c5to6));

				
	full_adder bit_6(	.a(b[6]), 
				.b(a[6]), 
				.cin(c5to6),
				.s(s[6]),
				.cout(c6to7));


endmodule

