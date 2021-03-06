
void usage (char * prog) {

#ifdef CAP2RPC
	fprintf(stderr,"Usage: %s [-v] [-i interface] [-p \"parsefilter\"] [-di ipaddress] [-dp port ] \n", prog);
	fprintf(stderr,"Usage: -V\n");
	fprintf(stderr,"Usage: -h\n");
	return;
#endif

#ifdef RPC2AMB
	fprintf(stderr,"Usage: %s [-v] [-si ipaddress ] [-sp port] [-di ipaddress] [-dp port ] [-dpi portincease] module ... [module]\n", prog);
	fprintf(stderr,"Usage: -V\n");
	fprintf(stderr,"Usage: -h\n");
	return;
#endif

#ifdef AMB2PCM
	fprintf(stderr,"Usage: %s [-dng device] [-v] [-g gain] [-li ipaddress ] [ -lp port] [ -si ipaddress] [ -sp port ] [-am || module [module ..] ]\n",prog);
	fprintf(stderr,"Usage: -V\n");
	fprintf(stderr,"Usage: -h\n");
	return;
#endif

#ifdef PCM2STDOUT
	fprintf(stderr,"Usage: %s [-v] [ [-s] || [-n] ]  [-si ipaddress] [-sp port]\n",prog);
	fprintf(stderr,"Usage: -V\n");
	fprintf(stderr,"Usage: -h\n");
	return;
#endif

#ifdef XRF2AMB
	fprintf(stderr,"Usage: %s [-v] [-4] [-6]  [-di ipaddress] [-dp port] [-dpi portincrease] [-rp port] MYCALL reflector\n",prog);
	fprintf(stderr,"Usage: -V\n");
	fprintf(stderr,"Usage: -h\n");
	return;
#endif

#ifdef DPL2AMB
	fprintf(stderr,"Usage: %s [-v] [-4] [-6]  [-di ipaddress] [-dp port] [-dpi portincrease] [-rp port] MYCALL gateway gatewayhost\n",prog);
	fprintf(stderr,"Usage: -V\n");
	fprintf(stderr,"Usage: -h\n");
	return;
#endif

#ifdef UDPBOUNCE
	fprintf(stderr,"Usage: %s [-v] [-t timeout] [-mj multicast-ipaddress] -s udpport -d ipaddress udpport\n",prog);
	fprintf(stderr,"Usage: -V\n");
	fprintf(stderr,"Usage: -h\n");
	return;
#endif

// unknown application
fprintf(stderr,"Error, called \"usage\" in unknown application! \n");

}; // end usage


void help (char * prog) {
#ifdef CAP2RPC
	fprintf(stderr,"%s: intercept traffic between i-com repeater controller and gateway-server\n",prog);
	fprintf(stderr,"and create a RPC stream\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"Usage: %s [-v ] [-i interface] [-p \"parsefilter\"] [-di ipaddress] [-dp port ] \n", prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"This application captures all traffic on the ethernet interface between the\n");
	fprintf(stderr,"i-com RPC (repeater controller) and the gateway-server.\n");
	fprintf(stderr,"It creates a \"RPC\" stream from this, which contains a copy of these packets\n");
	fprintf(stderr,"from the IP level upwards\n");
	fprintf(stderr,"This application needs root-access to run correctly, so should be installed with\n");
	fprintf(stderr,"setuid priviledges\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"Options:\n");
	fprintf(stderr,"-i: capturing interface (default: %s)\n",default_interface);
	fprintf(stderr,"-p: capturing parse-filter (default: %s)\n",default_parsefilter);
	fprintf(stderr,"\n");
	fprintf(stderr,"-di: destination IP-address (default %s)\n",default_d_ipaddress);
	fprintf(stderr,"-dp: destination UDP port (default %d)\n",default_d_port);
	fprintf(stderr,"\n");
	fprintf(stderr,"-v: increase verboselevel (may be entered multiple times)\n");
	return;
#endif


#ifdef RPC2AMB
	fprintf(stderr,"%s: create one or multiple AMB-streams from a RPC stream\n", prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"Usage: %s [-v ] [-si ipaddress ] [-sp port] [-di ipaddress] [-dp port ] [-dpi portincease] module ... [module]\n", prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"This application subscribes to a RPC multicast-stream, splits it up into\n");
	fprintf(stderr,"it into one or multiple AMB-streams (one per module) and rebroadcasts\n");
	fprintf(stderr,"these as a DSTK AMB-stream.\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"The generated AMB-stream can be send to a different destination UDP port\n");
	fprintf(stderr,"per incoming repeater-module or can all be send to the same destination\n");
	fprintf(stderr,"UDP port using the \"destination-port increase\" option.\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"Options:\n");
	fprintf(stderr,"-si: source IP-address (default %s)\n",default_s_ipaddress);
	fprintf(stderr,"-sp: source UDP port (default %d)\n",default_s_port);
	fprintf(stderr,"\n");
	fprintf(stderr,"-di: destination IP-address (default %s)\n",default_d_ipaddress);
	fprintf(stderr,"-dp: destination UDP port (default %d)\n",default_d_port);
	fprintf(stderr,"-dpi: destination UDP port increasement (default %d)\n",default_d_portincr);
	fprintf(stderr,"\n");
	fprintf(stderr,"[module]: modules on which rpc-to-amb conversion is done.\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"-v: increase verboselevel (may be entered multiple times)\n");
	fprintf(stderr,"-myip: my IP-address on interface facing RPC. Used to determine direction\n");

	return;
#endif

#ifdef AMB2PCM
	fprintf(stderr,"%s: Decode AMB-streams to PCM stream\n", prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"Usage: %s [-dng device] [-v] [-g gain] [-si ipaddress ] [ -sp port] [ -di ipaddress] [ -dp port ] [-am || module [module ..] ]\n",prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"This application subscribes to a AMB multicast-stream, decodes it to PCM\n");
	fprintf(stderr,"format using a DVdongle and rebroadcasts it as a PCM-stream\n");
	fprintf(stderr,"these as a DSTK AMB-stream.\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"Decoding is done per conversation. If multiple AMB-streams are send to the same\n");
	fprintf(stderr,"multicast IP-address and UDP-port, one one single conversation will be decoded at\n");
	fprintf(stderr,"once.\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"Options:\n");
	fprintf(stderr,"-si: source IP-address (default %s)\n",default_s_ipaddress);
	fprintf(stderr,"-sp: source UDP port (default %d)\n",default_s_port);
	fprintf(stderr,"-di: destination IP-address (default %s)\n",default_d_ipaddress);
	fprintf(stderr,"-dp: destination UDP port (default %d)\n",default_d_port);
	fprintf(stderr,"\n");
	fprintf(stderr,"-dng: dongle device (default: %s)\n",default_dongledevice);
	fprintf(stderr,"-g; PCM gain (default: %d)\n",default_ambegain);
	fprintf(stderr,"\n");
	fprintf(stderr,"-am: Any module: accept stream from any module\n");
	fprintf(stderr,"module: listen to traffic from/to a particular module\n");
	fprintf(stderr,"modules can be A, B or C for repeater modules, or RA, RB or RC for reflector modules\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"-v: increase verboselevel (may be used multiple times)\n");

	return;
#endif

#ifdef PCM2STDOUT
	fprintf(stderr,"%s: Sent PCM stream to external application or file via standard-out.\n", prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"Usage: %s [-v] [ [-s] || [-n] ]  [-si ipaddress] [-sp port]\n",prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"This application subscribes to a PCM multicast-stream, send it to standard-out,\n");
	fprintf(stderr,"optionally adding silence or comfort noise when no audio is being received.\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"This application can be used to save a PCM-stream to a file or\n");
	fprintf(stderr,"pipe it to an external application for further processing\n");
	fprintf(stderr,"As the length of the PCM-stream is not known beforehand, this application\n");
	fprintf(stderr,"generated  \"raw\" PCM without a PCM-header.\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"Options:\n");
	fprintf(stderr,"-si: source IP-address (default %s)\n",default_s_ipaddress);
	fprintf(stderr,"-sp: source UDP port (default %d)\n",default_s_port);
	fprintf(stderr,"\n");
	fprintf(stderr,"-s: generate silence when no data is received\n");
	fprintf(stderr,"-n: generate noise when no data is received\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"-v: increase verboselevel (may be used multiple times)\n");
	return;
#endif

#ifdef XRF2AMB
	fprintf(stderr,"%s: Connect to X-reflector/gateway and forward traffic to AMBE stream.\n",prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"Usage: %s [-v] [-4] [-6]  [-di ipaddress] [-dp port] [-dpi portincrease] [-rp port] MYCALL reflectorhost\n",prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"This application connects to a dextra X-reflector or a remote gateway using the\n");
	fprintf(stderr,"dextra linking protocol, simulating a DVdongle client\n");
	fprintf(stderr,"and forwards traffic received from the reflector to a local AMBE stream.\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"Options:\n");
	fprintf(stderr,"-di: destination IP-address (default %s)\n",default_d_ipaddress);
	fprintf(stderr,"-dp: destination UDP port (default %d)\n",default_d_port);
	fprintf(stderr,"-dpi: destination UDP port increasement (default %d)\n",default_d_portincr);
	fprintf(stderr,"\n");
	fprintf(stderr,"-rp: remote UDP port of reflector or gateway (default %d)\n",default_reflectorport);
	fprintf(stderr,"\n");
	fprintf(stderr,"-4: force ipv4-only address resolution of reflectorhost\n");
	fprintf(stderr,"-6: force ipv6-only address resolution of reflectorhost\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"-v: increase verboselevel (may be used multiple times)\n");
	return;
#endif


#ifdef DPL2AMB
	fprintf(stderr,"%s: Connect to dplus reflector/gateway and forward traffic to AMBE stream.\n",prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"Usage: %s [-v] [-4] [-6]  [-di ipaddress] [-dp port] [-dpi portincrease] [-rp port] MYCALL gateway gatewayhost\n",prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"This application connects to a dplus reflector or a remote gateway using the\n");
	fprintf(stderr,"dplus linking protocol, simulating a DVdongle client\n");
	fprintf(stderr,"and forwards traffic received from the reflector to a local AMBE stream.\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"Options:\n");
	fprintf(stderr,"-di: destination IP-address (default %s)\n",default_d_ipaddress);
	fprintf(stderr,"-dp: destination UDP port (default %d)\n",default_d_port);
	fprintf(stderr,"-dpi: destination UDP port increasement (default %d)\n",default_d_portincr);
	fprintf(stderr,"\n");
	fprintf(stderr,"-rp: remote UDP port of reflector or gateway (default %d)\n",default_gatewayport);
	fprintf(stderr,"\n");
	fprintf(stderr,"-4: force ipv4-only address resolution of reflectorhost\n");
	fprintf(stderr,"-6: force ipv6-only address resolution of reflectorhost\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"-v: increase verboselevel (may be used multiple times)\n");
	return;
#endif

#ifdef UDPBOUNCE
	fprintf(stderr,"%s: Retransmit UDP packets from/to unicast or multicast\n",prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"Usage: %s [-v] [-t timeout] [-mj multicast-ipaddress] -s udpport -d ipaddress udpport\n",prog);
	fprintf(stderr,"\n");
	fprintf(stderr,"This application retransmits UDP unicast or multicast packets it receives via\n");
	fprintf(stderr,"unicast or multicast.\n");
	fprintf(stderr,"It can be used to transport bounce multicast UDP packet (as used by the\n");
	fprintf(stderr,"DSTK) to external hosts using unicast UDP\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"Options:\n");
	fprintf(stderr,"-s: SOURCE-UDP port\n");
	fprintf(stderr,"-d: DESTINATION-UDP ipaddress port\n");
	fprintf(stderr,"\n");
	fprintf(stderr,"-mj: do a multicast join request for a multicast address \n");
	fprintf(stderr,"\n");
	fprintf(stderr,"-t: timeout: exit the application if no data received during a given number of seconds. (Default 0: no timeout) \n");
	fprintf(stderr,"\n");
	return;
#endif

// unknown application
fprintf(stderr,"Error, called \"Help\" in unknown application! \n");

}; // end function help

