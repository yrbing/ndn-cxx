/* 
 * Author: Jeff Thompson
 *
 * BSD license, See the LICENSE file for more information.
 */

#ifndef NDN_INTEREST_H
#define	NDN_INTEREST_H

#include "Name.h"

#ifdef	__cplusplus
extern "C" {
#endif

struct ndn_Interest {
  struct ndn_Name name;
	int maxSuffixComponents;  /**< -1 for none */
	int minSuffixComponents;  /**< -1 for none */
	unsigned char *publisherPublicKeyDigest;      /**< pointer to pre-allocated buffer.  0 for none */
  unsigned int publisherPublicKeyDigestLength; /**< length of publisherPublicKeyDigest */
	// TODO: implement exclude
	int childSelector;        /**< -1 for none */
	int answerOriginKind;     /**< -1 for none */
	int scope;                /**< -1 for none */
	int interestLifetime;     /**< milliseconds. -1 for none */
	unsigned char *nonce;	    /**< pointer to pre-allocated buffer.  0 for none */
  unsigned int nonceLength; /**< length of nonce */
};

static inline void ndn_Interest_init(struct ndn_Interest *self, struct ndn_NameComponent *nameComponents, unsigned int maxNameComponents) 
{
  ndn_Name_init(&self->name, nameComponents, maxNameComponents);
  self->maxSuffixComponents = -1;
	self->minSuffixComponents = -1;
	self->publisherPublicKeyDigest = 0;
	// TODO: implement exclude
	self->childSelector = -1;
	self->answerOriginKind = -1;
	self->scope = -1;
	self->interestLifetime = -1;
	self->nonce = 0; /**< length of nonce */
}

#ifdef	__cplusplus
}
#endif

#endif
