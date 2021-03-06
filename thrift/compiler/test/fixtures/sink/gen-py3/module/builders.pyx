#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
cdef class InitialResponse_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _module_types.InitialResponse

    def __iter__(self):
        yield "content", self.content

cdef class FinalResponse_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _module_types.FinalResponse

    def __iter__(self):
        yield "content", self.content

cdef class SinkPayload_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _module_types.SinkPayload

    def __iter__(self):
        yield "content", self.content

cdef class CompatibleWithKeywordSink_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _module_types.CompatibleWithKeywordSink

    def __iter__(self):
        yield "sink", self.sink

cdef class InitialException_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _module_types.InitialException

    def __iter__(self):
        yield "reason", self.reason

cdef class SinkException1_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _module_types.SinkException1

    def __iter__(self):
        yield "reason", self.reason

cdef class SinkException2_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _module_types.SinkException2

    def __iter__(self):
        yield "reason", self.reason

