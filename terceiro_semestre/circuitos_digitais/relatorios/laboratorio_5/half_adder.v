module half_adder (
input	a,
input	b,
output	cout,
output	s);

    xor(s, a, b);
 
    and(cout, a, b);

endmodule

