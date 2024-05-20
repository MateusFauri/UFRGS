module tabuada7_7b (
input	eck,
input	er,
input	es,
input   eena,
input   ZERO,
input   UM,
output  [6:0] sq);

wire [6:0] ea; 
wire [6:0] nea;
wire [6:0] pe;
wire [6:0] valor;
wire tem70, tem30, tmp;

buf(valor[6], ZERO);
buf(valor[5], ZERO);
buf(valor[4], ZERO);
buf(valor[3], ZERO);
buf(valor[2], UM);
buf(valor[1], UM);
buf(valor[0], UM);

not(nea[0], ea[0]);
not(nea[1], ea[1]);
not(nea[2], ea[2]);
not(nea[3], ea[3]);
not(nea[4], ea[4]);
not(nea[5], ea[5]);
not(nea[6], ea[6]);

and(tem70, ea[6], nea[5], tem30);
and(tem30, nea[4], nea[3], ea[2], tmp);
and(tmp, ea[1], nea[0]);


reg7 meu_registrador_querido (.ed(pe), .eck(eck), .era(er), .ers(tem70),.es(es), .eena(eena), .sq(ea));

cc_saida xololo (.a(ea), .s(sq));

soma7b meu_somador_querido (.a(ea), .b(valor), .s(pe));
    

endmodule

