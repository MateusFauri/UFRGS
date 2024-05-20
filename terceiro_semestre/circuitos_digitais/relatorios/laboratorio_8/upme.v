module upme (
input   up,
input	eck,
input	er,
input	es,
input   eena,

output [3:0] sq,
output [1:0] oea,
output [1:0] ope);

wire [1:0] ea;
wire [1:0] pe;

buf(oea[1], ea[1]);
buf(oea[0], ea[0]);
buf(ope[1], pe[1]);
buf(ope[0], pe[0]);


upcc_pe proximo_estado (.inup(up), .inea(ea), .outpe(pe));

reg2 meu_registrador_querido (.ed(pe), .eck(eck), .er(er), 
.es(es), .eena(eena), .sq(ea));

cc_saida xololo (.a(ea), .s(sq));
    

endmodule

