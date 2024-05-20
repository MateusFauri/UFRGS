module cc_saida (
input	[1:0] a,
output	[3:0] s);

wire na,nb, low;

not(na, a[1]);
not(nb, a[0]);
and(low, a[1],na);

buf(s[3], low);
buf(s[2], nb);
buf(s[1], nb);
buf(s[0], na);



endmodule

