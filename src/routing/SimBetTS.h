/*
 *  Adyton: A Network Simulator for Opportunistic Networks
 *  Copyright (C) 2015-2018  Nikolaos Papanikos,
 *  Dimitrios-Georgios Akestoridis, and Evangelos Papapetrou
 *
 *  This file is part of Adyton.
 *
 *  Adyton is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Adyton is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Adyton.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Written by Nikolaos Papanikos and Dimitrios-Georgios Akestoridis.
 */


#include <stdio.h>
#include <stdlib.h>

#ifndef ROUTING_H
	#define ROUTING_H
	#include "Routing.h"
#endif

#ifndef ADJA_H
	#define ADJA_H
	#include "../data-structures/Adjacency.h"
#endif



class SimBetTS:public Routing
{
public:
	SimBetTS(PacketPool* PP, MAC* mc, PacketBuffer* Bf, int NID, Statistics *St, Settings *S, God *G);
	virtual void NewContact(double CTime, int NID);
	virtual void ContactRemoved(double CTime, int NID);
	virtual void Contact(double CTime, int NID);
	virtual void recv(double rTime, int pktID);
	~SimBetTS();
	Adjacency *Adja;

protected:
	virtual void AfterDirectTransfers(double CTime, int NID);
	virtual void SendPacket(double STime, int pktID, int nHop, int RepValue);

private:
	void ReceptionData(Header *hd, Packet *pkt, int PID, double CurrentTime, int RealID);
	void ReceptionRequestContacts(Header *hd, Packet *pkt, int PID, double CurrentTime);
	void ReceptionContacts(Header *hd, Packet *pkt, int PID, double CurrentTime);
	void ReceptionMetricsPerDest(Header *hd, Packet *pkt, int PID, double CurrentTime);
	void ReceptionReqForDest(Header *hd, Packet *pkt, int PID, double CurrentTime);
	bool PacketExists(int *PList, int p);
};
