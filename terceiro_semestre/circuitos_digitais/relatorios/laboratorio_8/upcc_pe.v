module upcc_pe (
input    inup,
input	[1:0] inea,
output	[1:0] outpe);

wire a,b,c, na, nb, nc;
wire primo0, primo1, primo2, primo3, primo4, primo5;

buf(a, inup);
buf(b, inea[1]);
buf(c, inea[0]);
not(nc, c);
not(nb, b);
not(na, a);

buf(primo0, nb );
and(primo1, na, c);
and(primo2, a, nc);

buf(primo3, nc);
and(primo4, na, nb);
and(primo5, a, b);

or(outpe[1], primo0, primo1, primo2);
or(outpe[0], primo3, primo4, primo5);

endmodule

