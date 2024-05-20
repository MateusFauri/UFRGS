module ffd (
input	ed,
input	eck,
input	er,
input	es,
input   eena,
output  sq);


    DFFRSE meu_ff_querido(	.q(sq), 
							.d(ed), 
							.clk(eck), 
							.reset(er), 
							.set(es), 
							.enable(eena));
    


endmodule

