// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_0HANDSHAKERET_S2C_H_
#define FLATBUFFERS_GENERATED_0HANDSHAKERET_S2C_H_

#include "flatbuffers/flatbuffers.h"

namespace s2c {

struct HandshakeRet;

struct HandshakeRet FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_VERSIONID = 4
  };
  uint16_t versionId() const { return GetField<uint16_t>(VT_VERSIONID, 0); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint16_t>(verifier, VT_VERSIONID) &&
           verifier.EndTable();
  }
};

struct HandshakeRetBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_versionId(uint16_t versionId) { fbb_.AddElement<uint16_t>(HandshakeRet::VT_VERSIONID, versionId, 0); }
  HandshakeRetBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  HandshakeRetBuilder &operator=(const HandshakeRetBuilder &);
  flatbuffers::Offset<HandshakeRet> Finish() {
    auto o = flatbuffers::Offset<HandshakeRet>(fbb_.EndTable(start_, 1));
    return o;
  }
};

inline flatbuffers::Offset<HandshakeRet> CreateHandshakeRet(flatbuffers::FlatBufferBuilder &_fbb,
    uint16_t versionId = 0) {
  HandshakeRetBuilder builder_(_fbb);
  builder_.add_versionId(versionId);
  return builder_.Finish();
}

inline const s2c::HandshakeRet *GetHandshakeRet(const void *buf) { return flatbuffers::GetRoot<s2c::HandshakeRet>(buf); }

inline bool VerifyHandshakeRetBuffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<s2c::HandshakeRet>(nullptr); }

inline void FinishHandshakeRetBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<s2c::HandshakeRet> root) { fbb.Finish(root); }

}  // namespace s2c

#endif  // FLATBUFFERS_GENERATED_0HANDSHAKERET_S2C_H_
