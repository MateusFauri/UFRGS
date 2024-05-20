module ffdex4 (
input	eck,
input	er,
input	es,
input   eena,
output  saida,
output  sck);

wire ed, armazenado, neck;
buf(saida, armazenado);
not(ed, armazenado);
not(neck, eck);
buf(sck, eck);

    DFFRSE meu_ff_querido(	.q(armazenado), 
							.d(ed), 
							.clk(neck), 
							.reset(er), 
							.set(es), 
							.enable(eena));
    


endmodule

