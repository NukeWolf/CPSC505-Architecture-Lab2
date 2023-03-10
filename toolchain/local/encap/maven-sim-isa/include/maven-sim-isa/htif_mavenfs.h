/* Author: Yunsup Lee
 *         Parallel Computing Laboratory
 *         Electrical Engineering and Computer Sciences
 *         University of California, Berkeley
 *
 * Copyright (c) 2008, The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the University of California, Berkeley nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE REGENTS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __HTIF_MIPSFS_H
#define __HTIF_MIPSFS_H

#include "htif.h"
#include "memif_mavenfs.h"
#include "simulator.h"

class htif_mavenfs_t : public htif_t
{
public:
    htif_mavenfs_t(simulator_t& sim);
    ~htif_mavenfs_t();
    memif_t& lmem();
    void set_reset(int val);
    void set_run(int val);
    int get_tohost();
    void set_fromhost(int val);
    int get_magicmemaddr();
    void set_magicmemaddr(int addr);
    long long get_cycle();
    int run_to_tohost(int origToHost);
    int set_num_cores(int n);
    void set_num_physical_regs(int nregs);
    void set_impl_flags(int reconvergence, bool density, bool scoreboard, bool bc, bool vxudebug);
    void set_logfile(FILE* logfile);

    // dumpstats
    void dumpstats(FILE*  logfile, double seconds = 0.0);

private:
    simulator_t& sim;
    memif_mavenfs_t* memif;

    int reset;
    int running;
};

#endif // __HTIF_MIPSFS_H
