/* soapStub.h
   Generated by gSOAP 2.8.6 from WsApi.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapStub_H
#define soapStub_H
#define SOAP_NAMESPACE_OF_ns1	"http://dei.isep.ipp.pt/"
#include "stdsoap2.h"

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_ns1__ArrayOfClassificacao
#define SOAP_TYPE_ns1__ArrayOfClassificacao (7)
/* ns1:ArrayOfClassificacao */
class SOAP_CMAC ns1__ArrayOfClassificacao
{
public:
	int __sizeClassificacao;	/* sequence of elements <Classificacao> */
	class ns1__Classificacao **Classificacao;	/* optional element of type ns1:Classificacao */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 7; } /* = unique id SOAP_TYPE_ns1__ArrayOfClassificacao */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ns1__ArrayOfClassificacao() { ns1__ArrayOfClassificacao::soap_default(NULL); }
	virtual ~ns1__ArrayOfClassificacao() { }
};
#endif

#ifndef SOAP_TYPE_ns1__Classificacao
#define SOAP_TYPE_ns1__Classificacao (8)
/* ns1:Classificacao */
class SOAP_CMAC ns1__Classificacao
{
public:
	int Posicao;	/* required element of type xsd:int */
	char *Nome;	/* optional element of type xsd:string */
	double Pontuacao;	/* required element of type xsd:double */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 8; } /* = unique id SOAP_TYPE_ns1__Classificacao */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ns1__Classificacao() { ns1__Classificacao::soap_default(NULL); }
	virtual ~ns1__Classificacao() { }
};
#endif

#ifndef SOAP_TYPE_ns1__ArrayOfTorneio
#define SOAP_TYPE_ns1__ArrayOfTorneio (9)
/* ns1:ArrayOfTorneio */
class SOAP_CMAC ns1__ArrayOfTorneio
{
public:
	int __sizeTorneio;	/* sequence of elements <Torneio> */
	class ns1__Torneio **Torneio;	/* optional element of type ns1:Torneio */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 9; } /* = unique id SOAP_TYPE_ns1__ArrayOfTorneio */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ns1__ArrayOfTorneio() { ns1__ArrayOfTorneio::soap_default(NULL); }
	virtual ~ns1__ArrayOfTorneio() { }
};
#endif

#ifndef SOAP_TYPE_ns1__Torneio
#define SOAP_TYPE_ns1__Torneio (10)
/* ns1:Torneio */
class SOAP_CMAC ns1__Torneio
{
public:
	int Id;	/* required element of type xsd:int */
	char *Nome;	/* optional element of type xsd:string */
	time_t DataInicio;	/* required element of type xsd:dateTime */
	time_t DataFim;	/* required element of type xsd:dateTime */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 10; } /* = unique id SOAP_TYPE_ns1__Torneio */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ns1__Torneio() { ns1__Torneio::soap_default(NULL); }
	virtual ~ns1__Torneio() { }
};
#endif

#ifndef SOAP_TYPE__ns1__setResultados
#define SOAP_TYPE__ns1__setResultados (11)
/* ns1:setResultados */
class SOAP_CMAC _ns1__setResultados
{
public:
	int utilizador;	/* required element of type xsd:int */
	int mapa;	/* required element of type xsd:int */
	int torneio;	/* required element of type xsd:int */
	double pontuacao;	/* required element of type xsd:double */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 11; } /* = unique id SOAP_TYPE__ns1__setResultados */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__setResultados() { _ns1__setResultados::soap_default(NULL); }
	virtual ~_ns1__setResultados() { }
};
#endif

#ifndef SOAP_TYPE__ns1__setResultadosResponse
#define SOAP_TYPE__ns1__setResultadosResponse (12)
/* ns1:setResultadosResponse */
class SOAP_CMAC _ns1__setResultadosResponse
{
public:
	ns1__ArrayOfClassificacao *setResultadosResult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ns1:ArrayOfClassificacao */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 12; } /* = unique id SOAP_TYPE__ns1__setResultadosResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__setResultadosResponse() { _ns1__setResultadosResponse::soap_default(NULL); }
	virtual ~_ns1__setResultadosResponse() { }
};
#endif

#ifndef SOAP_TYPE__ns1__getTorneio
#define SOAP_TYPE__ns1__getTorneio (13)
/* ns1:getTorneio */
class SOAP_CMAC _ns1__getTorneio
{
public:
	int utilizador;	/* required element of type xsd:int */
	int mapa;	/* required element of type xsd:int */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 13; } /* = unique id SOAP_TYPE__ns1__getTorneio */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__getTorneio() { _ns1__getTorneio::soap_default(NULL); }
	virtual ~_ns1__getTorneio() { }
};
#endif

#ifndef SOAP_TYPE__ns1__getTorneioResponse
#define SOAP_TYPE__ns1__getTorneioResponse (14)
/* ns1:getTorneioResponse */
class SOAP_CMAC _ns1__getTorneioResponse
{
public:
	ns1__ArrayOfTorneio *getTorneioResult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ns1:ArrayOfTorneio */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 14; } /* = unique id SOAP_TYPE__ns1__getTorneioResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__getTorneioResponse() { _ns1__getTorneioResponse::soap_default(NULL); }
	virtual ~_ns1__getTorneioResponse() { }
};
#endif

#ifndef SOAP_TYPE__ns1__login
#define SOAP_TYPE__ns1__login (15)
/* ns1:login */
class SOAP_CMAC _ns1__login
{
public:
	int utilizador;	/* required element of type xsd:int */
	char *md5password;	/* optional element of type xsd:string */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 15; } /* = unique id SOAP_TYPE__ns1__login */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__login() { _ns1__login::soap_default(NULL); }
	virtual ~_ns1__login() { }
};
#endif

#ifndef SOAP_TYPE__ns1__loginResponse
#define SOAP_TYPE__ns1__loginResponse (16)
/* ns1:loginResponse */
class SOAP_CMAC _ns1__loginResponse
{
public:
	int loginResult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 16; } /* = unique id SOAP_TYPE__ns1__loginResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__loginResponse() { _ns1__loginResponse::soap_default(NULL); }
	virtual ~_ns1__loginResponse() { }
};
#endif

#ifndef SOAP_TYPE___ns2__setResultados
#define SOAP_TYPE___ns2__setResultados (29)
/* Operation wrapper: */
struct __ns2__setResultados
{
public:
	_ns1__setResultados *ns1__setResultados;	/* optional element of type ns1:setResultados */
};
#endif

#ifndef SOAP_TYPE___ns2__getTorneio
#define SOAP_TYPE___ns2__getTorneio (33)
/* Operation wrapper: */
struct __ns2__getTorneio
{
public:
	_ns1__getTorneio *ns1__getTorneio;	/* optional element of type ns1:getTorneio */
};
#endif

#ifndef SOAP_TYPE___ns2__login
#define SOAP_TYPE___ns2__login (37)
/* Operation wrapper: */
struct __ns2__login
{
public:
	_ns1__login *ns1__login;	/* optional element of type ns1:login */
};
#endif

#ifndef SOAP_TYPE___ns3__setResultados
#define SOAP_TYPE___ns3__setResultados (39)
/* Operation wrapper: */
struct __ns3__setResultados
{
public:
	_ns1__setResultados *ns1__setResultados;	/* optional element of type ns1:setResultados */
};
#endif

#ifndef SOAP_TYPE___ns3__getTorneio
#define SOAP_TYPE___ns3__getTorneio (41)
/* Operation wrapper: */
struct __ns3__getTorneio
{
public:
	_ns1__getTorneio *ns1__getTorneio;	/* optional element of type ns1:getTorneio */
};
#endif

#ifndef SOAP_TYPE___ns3__login
#define SOAP_TYPE___ns3__login (43)
/* Operation wrapper: */
struct __ns3__login
{
public:
	_ns1__login *ns1__login;	/* optional element of type ns1:login */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (44)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (45)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (47)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (50)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (51)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


#endif

/* End of soapStub.h */
