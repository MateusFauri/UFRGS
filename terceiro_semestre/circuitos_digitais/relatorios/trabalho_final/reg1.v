module reg1 (
input	[1:0] ed,
input	eck,
input	er,
input	es,
input   eena,
output  [1:0] sq);


    DFFRSE meu_ff_0		(	.q(sq[0]), 
							.d(ed[0]), 
							.clk(eck), 
							.reset(er), 
							.set(es), 
							.enable(eena));
    
    DFFRSE meu_ff_1		(	.q(sq[1]), 
							.d(ed[1]), 
							.clk(eck), 
							.reset(er), 
							.set(es), 
							.enable(eena));
	
				

endmodule

