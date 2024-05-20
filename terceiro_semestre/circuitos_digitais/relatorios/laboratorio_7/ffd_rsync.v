module ffd_rsync (
input	ed,
input	eck,
input	er_async,
input	er_sync,
input	es,
input   eena,
output  sq);

    wire dint, ner_sync;
    not(ner_sync, er_sync);
    and(dint, ed, ner_sync);
    DFFRSE meu_ff_querido(	.q(sq), 
							.d(dint), 
							.clk(eck), 
							.reset(er_async), 
							.set(es), 
							.enable(eena));
    


endmodule

