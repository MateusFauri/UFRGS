module upme (
input   up,
input	eck,
input	er,
input	es,
input   high ,
input   low ,
output [3:0] sq,
output [3:0] oea);

wire [2:0] ea;
wire [2:0] pe;
wire enable;

buf(oea[3], up);
buf(oea[2], ea[2]);
buf(oea[1], ea[1]);
buf(oea[0], ea[0]);

upcc_pe proximo_estado (.inup(up), .inea(ea), .outpe(pe));

div_freq divisor_frequencia (.eck(eck), 
                            .er(er), 
                            .es(es), 
                            .eena(high), 
                            .enab(enable));

reg2 meu_registrador_querido (.ed(pe), 
                            .eck(eck), 
                            .er(er), 
                            .es(es), 
                            .eena(enable), 
                            .sq(ea));

cc_saida xololo (.a(ea), .s(sq));
    

endmodule

