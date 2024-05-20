module div_freq (
input   eck,
input   er,
input   es,
input   eena,
output	enab);

wire na, nb;
wire [1:0]  ea;
wire [1:0]  pe;

not(na, ea[1]);
not(nb, ea[0]);

buf(pe[1], ea[0]);
and(pe[0], nb, na);

reg1 registrador (.ed(pe), .eck(eck), .er(er), 
.es(es), .eena(eena), .sq(ea));


and(enab, nb,na);

endmodule