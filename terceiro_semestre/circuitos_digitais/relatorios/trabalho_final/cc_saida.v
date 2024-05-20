module cc_saida (
input	[2:0] a,
output	[3:0] s);

wire na,nb,nc, low;
not(na, a[2]);
not(nb, a[1]);
not(nc, a[0]);

and(low, a[1], na);

and(s[3], a[2], a[1]);
and(s[2], nb, a[0]);
and(s[1], a[2], nb);
and(s[0], a[1], a[0]);

endmodule

