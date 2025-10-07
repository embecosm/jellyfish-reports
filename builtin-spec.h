void __builtin_ttroc_dbg_postcode(uint64_t val);
void __builtin_ttroc_noc_fence(void);

void __builtin_ttroc_llk_intf_write(uint64_t addr, uint64_t val);
uint64_t __builtin_ttroc_llk_intf_read(uint64_t addr);

void __builtin_ttroc_fds_intf_write(uint64_t addr, uint64_t val);
uint64_t __builtin_ttroc_fds_intf_read(uint64_t addr);

uint64_t __builtin_ttroc_cs_alloc(void);
void __builtin_ttroc_cs_dealloc(uint64_t context);
void __builtin_ttroc_cs_save(uint64_t context);
void __builtin_ttroc_cs_restore(uint64_t context);

void __builtin_ttroc_addrgen_wr_reg(uint64_t cmdbuf, uint64_t reg,
                                    uint64_t val);
uint64_t __builtin_ttroc_addrgen_rd_reg(uint64_t cmdbuf, uint64_t reg);
void __builtin_ttroc_addrgen_reset(uint64_t cmdbuf);
void __builtin_ttroc_addrgen_reset_counter(uint64_t cmdbuf);

uint64_t __builtin_ttroc_addrgen_peek_src(uint64_t cmdbuf);
uint64_t __builtin_ttroc_addrgen_pop_src(uint64_t cmdbuf);
uint64_t __builtin_ttroc_addrgen_pop_x_src(uint64_t cmdbuf, uint64_t skip_src);

uint64_t __builtin_ttroc_addrgen_peek_dest(uint64_t cmdbuf);
uint64_t __builtin_ttroc_addrgen_pop_dest(uint64_t cmdbuf);
uint64_t __builtin_ttroc_addrgen_pop_x_dest(uint64_t cmdbuf,
                                            uint64_t skip_dest);

uint64_t __builtin_ttroc_addrgen_pop_both(uint64_t cmdbuf, uint64_t skip_src,
                                          uint64_t skip_dest);

void __builtin_ttroc_addrgen_push_src(uint64_t cmdbuf);
void __builtin_ttroc_addrgen_push_src_pop_x(uint64_t cmdbuf, uint64_t skip_src);

void __builtin_ttroc_addrgen_push_dest(uint64_t cmdbuf);
void __builtin_ttroc_addrgen_push_dest_pop_x(uint64_t cmdbuf,
                                             uint64_t skip_dest);

void __builtin_ttroc_addrgen_push_both(uint64_t cmdbuf);
void __builtin_ttroc_addrgen_push_both_pop_x(uint64_t cmdbuf, uint64_t skip_src,
                                             uint64_t skip_dest);

void __builtin_ttroc_cmdbuf_wr_reg(uint64_t cmdbuf, uint64_t reg, uint64_t val);
uint64_t __builtin_ttroc_cmdbuf_rd_reg(uint64_t cmdbuf, uint64_t reg);

uint64_t __builtin_ttroc_cmdbuf_get_vc_space(uint64_t cmdbuf);
uint64_t __builtin_ttroc_cmdbuf_get_vc_space_vc(uint64_t cmdbuf, uint64_t vc);

uint64_t __builtin_ttroc_cmdbuf_wr_sent(uint64_t cmdbuf);
uint64_t __builtin_ttroc_cmdbuf_wr_sent_trid(uint64_t cmdbuf, uint64_t trid);

uint64_t __builtin_ttroc_cmdbuf_tr_ack(uint64_t cmdbuf);
uint64_t __builtin_ttroc_cmdbuf_tr_ack_trid(uint64_t cmdbuf, uint64_t trid);

void __builtin_ttroc_cmdbuf_reset(uint64_t cmdbuf);

uint64_t __builtin_ttroc_cmdbuf_idma_get_vc_space(uint64_t cmdbuf);
uint64_t __builtin_ttroc_cmdbuf_idma_get_vc_space_vc(uint64_t cmdbuf,
                                                     uint64_t vc);

uint64_t __builtin_ttroc_cmdbuf_idma_tr_ack(uint64_t cmdbuf);
uint64_t __builtin_ttroc_cmdbuf_idma_tr_ack_trid(uint64_t cmdbuf,
                                                 uint64_t trid);

void __builtin_ttroc_cmdbuf_issue_trans(uint64_t cmdbuf);
void __builtin_ttroc_cmdbuf_issue_inline_trans(uint64_t cmdbuf, uint64_t val);
void __builtin_ttroc_cmdbuf_issue_inline_addr_trans(uint64_t cmdbuf,
                                                    uint64_t val, uint64_t rs2);

void __builtin_ttroc_cmdbuf_issue_read1_trans(uint64_t cmdbuf, uint64_t rs1);
void __builtin_ttroc_cmdbuf_issue_read2_trans(uint64_t cmdbuf, uint64_t rs1,
                                              uint64_t rs2);

void __builtin_ttroc_cmdbuf_issue_write1_trans(uint64_t cmdbuf, uint64_t rs1);
void __builtin_ttroc_cmdbuf_issue_write2_trans(uint64_t cmdbuf, uint64_t rs1,
                                               uint64_t rs2);

void __builtin_ttroc_scmdbuf_wr_reg(uint64_t reg, uint64_t val);
uint64_t __builtin_ttroc_scmdbuf_rd_reg(uint64_t reg);

uint64_t __builtin_ttroc_scmdbuf_get_vc_space(void);
uint64_t __builtin_ttroc_scmdbuf_get_vc_space_vc(uint64_t vc);

uint64_t __builtin_ttroc_scmdbuf_wr_sent(void);
uint64_t __builtin_ttroc_scmdbuf_wr_sent_trid(uint64_t trid);

uint64_t __builtin_ttroc_scmdbuf_tr_ack(void);
uint64_t __builtin_ttroc_scmdbuf_tr_ack_trid(uint64_t trid);

void __builtin_ttroc_scmdbuf_reset(void);

uint64_t __builtin_ttroc_scmdbuf_idma_get_vc_space(void);
uint64_t __builtin_ttroc_scmdbuf_idma_get_vc_space_vc(uint64_t vc);

uint64_t __builtin_ttroc_scmdbuf_idma_tr_ack(void);
uint64_t __builtin_ttroc_scmdbuf_idma_tr_ack_trid(uint64_t trid);

void __builtin_ttroc_scmdbuf_issue_trans(void);
void __builtin_ttroc_scmdbuf_issue_inline_trans(uint64_t val);
void __builtin_ttroc_scmdbuf_issue_inline_addr_trans(uint64_t val,
                                                     uint64_t rs2);

void __builtin_ttroc_scmdbuf_issue_read1_trans(uint64_t rs1);
void __builtin_ttroc_scmdbuf_issue_read2_trans(uint64_t rs1, uint64_t rs2);

void __builtin_ttroc_scmdbuf_issue_write1_trans(uint64_t rs1);
void __builtin_ttroc_scmdbuf_issue_write2_trans(uint64_t rs1, uint64_t rs2);
