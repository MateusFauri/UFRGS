module full_adder (
input	a,
input	b,
input	cin,
output	cout,
output	s);

    wire huguinho, zezinho, luizinho;
or(cout, huguinho, zezinho, luizinho);
    xor(s, a, b, cin);
 
    and(huguinho, a, b);
    and(zezinho, a, cin);
	and(luizinho, b, cin);
    

endmodule

