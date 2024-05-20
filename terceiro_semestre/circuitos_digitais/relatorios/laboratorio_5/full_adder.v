module full_adder (
input	a,
input	b,
input	cin,
output	cout,
output	s);

    wire fio1, fio2, fio3;

    xor(s, a, b, cin);
 
    and(fio1, a, b);
    and(fio2, a, cin);
	and(fio3, b, cin);
    or(cout, fio1, fio2, fio3);

endmodule

