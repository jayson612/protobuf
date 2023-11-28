// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: awesomedata.proto

#include "awesomedata.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf {
class AwesomeDataDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<AwesomeData>
      _instance;
} _AwesomeData_default_instance_;
}  // namespace protobuf
namespace protobuf_awesomedata_2eproto {
static void InitDefaultsAwesomeData() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::protobuf::_AwesomeData_default_instance_;
    new (ptr) ::protobuf::AwesomeData();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protobuf::AwesomeData::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_AwesomeData =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsAwesomeData}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_AwesomeData.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf::AwesomeData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf::AwesomeData, somestring_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf::AwesomeData, somearray_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::protobuf::AwesomeData)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::protobuf::_AwesomeData_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "awesomedata.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\021awesomedata.proto\022\010protobuf\"4\n\013Awesome"
      "Data\022\022\n\nsomestring\030\001 \001(\t\022\021\n\tsomearray\030\002 "
      "\003(\002b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 91);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "awesomedata.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_awesomedata_2eproto
namespace protobuf {

// ===================================================================

void AwesomeData::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int AwesomeData::kSomestringFieldNumber;
const int AwesomeData::kSomearrayFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

AwesomeData::AwesomeData()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_awesomedata_2eproto::scc_info_AwesomeData.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:protobuf.AwesomeData)
}
AwesomeData::AwesomeData(const AwesomeData& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      somearray_(from.somearray_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  somestring_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.somestring().size() > 0) {
    somestring_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.somestring_);
  }
  // @@protoc_insertion_point(copy_constructor:protobuf.AwesomeData)
}

void AwesomeData::SharedCtor() {
  somestring_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

AwesomeData::~AwesomeData() {
  // @@protoc_insertion_point(destructor:protobuf.AwesomeData)
  SharedDtor();
}

void AwesomeData::SharedDtor() {
  somestring_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void AwesomeData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* AwesomeData::descriptor() {
  ::protobuf_awesomedata_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_awesomedata_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const AwesomeData& AwesomeData::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_awesomedata_2eproto::scc_info_AwesomeData.base);
  return *internal_default_instance();
}


void AwesomeData::Clear() {
// @@protoc_insertion_point(message_clear_start:protobuf.AwesomeData)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  somearray_.Clear();
  somestring_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool AwesomeData::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protobuf.AwesomeData)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string somestring = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_somestring()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->somestring().data(), static_cast<int>(this->somestring().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "protobuf.AwesomeData.somestring"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated float somearray = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, this->mutable_somearray())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(21u /* 21 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 1, 18u, input, this->mutable_somearray())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protobuf.AwesomeData)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protobuf.AwesomeData)
  return false;
#undef DO_
}

void AwesomeData::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protobuf.AwesomeData)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string somestring = 1;
  if (this->somestring().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->somestring().data(), static_cast<int>(this->somestring().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "protobuf.AwesomeData.somestring");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->somestring(), output);
  }

  // repeated float somearray = 2;
  if (this->somearray_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(2, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(static_cast< ::google::protobuf::uint32>(
        _somearray_cached_byte_size_));
    ::google::protobuf::internal::WireFormatLite::WriteFloatArray(
      this->somearray().data(), this->somearray_size(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:protobuf.AwesomeData)
}

::google::protobuf::uint8* AwesomeData::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:protobuf.AwesomeData)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string somestring = 1;
  if (this->somestring().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->somestring().data(), static_cast<int>(this->somestring().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "protobuf.AwesomeData.somestring");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->somestring(), target);
  }

  // repeated float somearray = 2;
  if (this->somearray_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      2,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
        static_cast< ::google::protobuf::int32>(
            _somearray_cached_byte_size_), target);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteFloatNoTagToArray(this->somearray_, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protobuf.AwesomeData)
  return target;
}

size_t AwesomeData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protobuf.AwesomeData)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated float somearray = 2;
  {
    unsigned int count = static_cast<unsigned int>(this->somearray_size());
    size_t data_size = 4UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
            static_cast< ::google::protobuf::int32>(data_size));
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _somearray_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // string somestring = 1;
  if (this->somestring().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->somestring());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void AwesomeData::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:protobuf.AwesomeData)
  GOOGLE_DCHECK_NE(&from, this);
  const AwesomeData* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const AwesomeData>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:protobuf.AwesomeData)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:protobuf.AwesomeData)
    MergeFrom(*source);
  }
}

void AwesomeData::MergeFrom(const AwesomeData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protobuf.AwesomeData)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  somearray_.MergeFrom(from.somearray_);
  if (from.somestring().size() > 0) {

    somestring_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.somestring_);
  }
}

void AwesomeData::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:protobuf.AwesomeData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AwesomeData::CopyFrom(const AwesomeData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protobuf.AwesomeData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AwesomeData::IsInitialized() const {
  return true;
}

void AwesomeData::Swap(AwesomeData* other) {
  if (other == this) return;
  InternalSwap(other);
}
void AwesomeData::InternalSwap(AwesomeData* other) {
  using std::swap;
  somearray_.InternalSwap(&other->somearray_);
  somestring_.Swap(&other->somestring_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata AwesomeData::GetMetadata() const {
  protobuf_awesomedata_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_awesomedata_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::protobuf::AwesomeData* Arena::CreateMaybeMessage< ::protobuf::AwesomeData >(Arena* arena) {
  return Arena::CreateInternal< ::protobuf::AwesomeData >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)