module upcc_pe (
input    inup,
input	[2:0] inea,
output	[2:0] outpe);

wire a,b,c,d, na, nb, nc, nd;
wire [4:0] primo0;
wire [4:0] primo1;
wire [2:0] primo2;
wire [1:0] juncao;

buf(a, inup);
buf(b, inea[2]);
buf(c, inea[1]);
buf(d, inea[0]);

not(nd, d);
not(nc, c);
not(nb, b);
not(na, a);

// logica dos estados

and(primo0[0], na,nc ,d);
and(primo0[1], na, c,nd);
and(primo0[2], a, nb,c);
and(primo0[3], a, b, nc);
and(primo0[4], primo0[3], nd);

and(primo1[0], na, b);
and(primo1[1], b, nc);
and(primo1[2], b, d);
and(primo1[3], a, nb, c);
and(primo1[4], primo1[3], nd);

buf(primo2[0], nb);
and(primo2[1], na, nd);
and(primo2[2], a, c);

//finalização

or(juncao[0], primo0[0], primo0[1], primo0[2]);
or(outpe[0], juncao[0], primo0[4]);

or(juncao[1], primo1[0], primo1[1], primo1[2] );
or(outpe[1], juncao[1], primo1[4]);

or(outpe[2], primo2[0], primo2[1], primo2[2]);

endmodule

