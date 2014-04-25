/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil -*- */
/**
 * Copyright (c) 2013-2014,  Regents of the University of California.
 * All rights reserved.
 *
 * This file is part of ndn-cxx library (NDN C++ library with eXperimental eXtensions).
 * See AUTHORS.md for complete list of ndn-cxx authors and contributors.
 *
 * This file licensed under New BSD License.  See COPYING for detailed information about
 * ndn-cxx library copyright, permissions, and redistribution restrictions.
 */

#ifndef NDN_SIGNATURE_HPP
#define NDN_SIGNATURE_HPP

namespace ndn {

/**
 * A Signature is storage for the signature-related information (info and value) in a Data packet.
 */
class Signature
{
public:
  class Error : public Tlv::Error
  {
  public:
    explicit
    Error(const std::string& what)
      : Tlv::Error(what)
    {
    }
  };

  enum {
    Sha256 = 0,
    Sha256WithRsa = 1
  };

  Signature()
    : m_type(-1)
  {
  }

  Signature(const Block& info, const Block& value = Block())
    : m_value(value)
  {
    setInfo(info);
  }

  operator bool() const
  {
    return m_type != -1;
  }

  uint32_t
  getType() const
  {
    return m_type;
  }

  const Block&
  getInfo() const
  {
    m_info.encode(); // will do nothing if wire already exists
    return m_info;
  }

  void
  setInfo(const Block& info)
  {
    m_info = info;
    if (m_info.hasWire() || m_info.hasValue())
      {
        m_info.parse();
        const Block& signatureType = m_info.get(Tlv::SignatureType);
        m_type = readNonNegativeInteger(signatureType);
      }
    else
      {
        m_type = -1;
      }
  }

  const Block&
  getValue() const
  {
    m_value.encode(); // will do nothing if wire already exists
    return m_value;
  }

  void
  setValue(const Block& value)
  {
    m_value = value;
  }

  void
  reset()
  {
    m_type = -1;
    m_info.reset();
    m_value.reset();
  }

public: // EqualityComparable concept
  bool
  operator==(const Signature& other) const
  {
    return getInfo() == other.getInfo() &&
      getValue() == other.getValue();
  }

  bool
  operator!=(const Signature& other) const
  {
    return !(*this == other);
  }

protected:
  int32_t m_type;

  mutable Block m_info;
  mutable Block m_value;
};

} // namespace ndn

#endif // NDN_SIGNATURE_HPP
