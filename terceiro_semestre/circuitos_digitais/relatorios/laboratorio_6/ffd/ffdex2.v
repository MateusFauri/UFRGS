module ffdex2 (
input	eck,
input	er,
input	es,
input   eena,
output  saida,
output sck);

wire ed, armazenado;
buf(saida, armazenado);
not(ed, armazenado);
buf(sck, eck);

    DFFRSE meu_ff_querido(	.q(armazenado), 
							.d(ed), 
							.clk(eck), 
							.reset(er), 
							.set(es), 
							.enable(eena));
    


endmodule

