# Created by: Ben Lavery <ben.lavery@hashbang0.com>
# $FreeBSD$

PORTNAME=	bunnysay
PORTVERSION=	1.1
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	ben.lavery@hashbang0.com
COMMENT=	Bunny Sign for terminals with UTF-8 support

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gmake

ALL_TARGET=	bunnysay

USE_GITHUB=	yes
GH_ACCOUNT=	co60ca

PLIST_FILES=	bin/bunnysay

post-extract:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bunnysay ${STAGEDIR}${PREFIX}/bin/${PORTNAME} 

.include <bsd.port.mk>
