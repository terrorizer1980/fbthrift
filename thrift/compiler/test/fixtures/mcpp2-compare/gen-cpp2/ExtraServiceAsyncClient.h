/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/extra_services_types.h"
#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/ParamServiceAsyncClient.h"
#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/module_types.h"

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace extra { namespace svc {

class ExtraServiceAsyncClient : public ::some::valid::ns::ParamServiceAsyncClient {
 public:
  using ::some::valid::ns::ParamServiceAsyncClient::ParamServiceAsyncClient;

  char const* getServiceName() const noexcept override {
    return "ExtraService";
  }

  virtual void simple_function(std::unique_ptr<apache::thrift::RequestCallback> callback);
  virtual void simple_function(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback);
 protected:
  void simple_functionImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback);
 public:
  virtual bool sync_simple_function();
  virtual bool sync_simple_function(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::Future<bool> future_simple_function();
  virtual folly::SemiFuture<bool> semifuture_simple_function();
  virtual folly::Future<bool> future_simple_function(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<bool> semifuture_simple_function(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::Future<std::pair<bool, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_simple_function(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<std::pair<bool, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_simple_function(apache::thrift::RpcOptions& rpcOptions);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<bool> co_simple_function() {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_return co_await folly::coro::detachOnCancel(semifuture_simple_function());
    } else {
      co_return co_await semifuture_simple_function();
    }
  }
  template <int = 0>
  folly::coro::Task<bool> co_simple_function(apache::thrift::RpcOptions& rpcOptions) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_return co_await folly::coro::detachOnCancel(semifuture_simple_function(rpcOptions));
    } else {
      co_return co_await semifuture_simple_function(rpcOptions);
    }
  }
#endif // FOLLY_HAS_COROUTINES
  virtual void simple_function(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback);
  static folly::exception_wrapper recv_wrapped_simple_function(bool& _return, ::apache::thrift::ClientReceiveState& state);
  static bool recv_simple_function(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual bool recv_instance_simple_function(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_simple_function(bool& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void simple_functionT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback);
 public:
  virtual void throws_function(std::unique_ptr<apache::thrift::RequestCallback> callback);
  virtual void throws_function(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback);
 protected:
  void throws_functionImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback);
 public:
  virtual void sync_throws_function();
  virtual void sync_throws_function(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::Future<folly::Unit> future_throws_function();
  virtual folly::SemiFuture<folly::Unit> semifuture_throws_function();
  virtual folly::Future<folly::Unit> future_throws_function(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<folly::Unit> semifuture_throws_function(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_throws_function(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_throws_function(apache::thrift::RpcOptions& rpcOptions);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<void> co_throws_function() {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_await folly::coro::detachOnCancel(semifuture_throws_function());
    } else {
      co_await semifuture_throws_function();
    }
  }
  template <int = 0>
  folly::coro::Task<void> co_throws_function(apache::thrift::RpcOptions& rpcOptions) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_await folly::coro::detachOnCancel(semifuture_throws_function(rpcOptions));
    } else {
      co_await semifuture_throws_function(rpcOptions);
    }
  }
#endif // FOLLY_HAS_COROUTINES
  virtual void throws_function(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback);
  static folly::exception_wrapper recv_wrapped_throws_function(::apache::thrift::ClientReceiveState& state);
  static void recv_throws_function(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_throws_function(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_throws_function(::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void throws_functionT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback);
 public:
  virtual void throws_function2(std::unique_ptr<apache::thrift::RequestCallback> callback, bool param1);
  virtual void throws_function2(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, bool param1);
 protected:
  void throws_function2Impl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, bool param1);
 public:
  virtual bool sync_throws_function2(bool param1);
  virtual bool sync_throws_function2(apache::thrift::RpcOptions& rpcOptions, bool param1);
  virtual folly::Future<bool> future_throws_function2(bool param1);
  virtual folly::SemiFuture<bool> semifuture_throws_function2(bool param1);
  virtual folly::Future<bool> future_throws_function2(apache::thrift::RpcOptions& rpcOptions, bool param1);
  virtual folly::SemiFuture<bool> semifuture_throws_function2(apache::thrift::RpcOptions& rpcOptions, bool param1);
  virtual folly::Future<std::pair<bool, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_throws_function2(apache::thrift::RpcOptions& rpcOptions, bool param1);
  virtual folly::SemiFuture<std::pair<bool, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_throws_function2(apache::thrift::RpcOptions& rpcOptions, bool param1);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<bool> co_throws_function2(bool param1) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_return co_await folly::coro::detachOnCancel(semifuture_throws_function2(param1));
    } else {
      co_return co_await semifuture_throws_function2(param1);
    }
  }
  template <int = 0>
  folly::coro::Task<bool> co_throws_function2(apache::thrift::RpcOptions& rpcOptions, bool param1) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_return co_await folly::coro::detachOnCancel(semifuture_throws_function2(rpcOptions, param1));
    } else {
      co_return co_await semifuture_throws_function2(rpcOptions, param1);
    }
  }
#endif // FOLLY_HAS_COROUTINES
  virtual void throws_function2(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, bool param1);
  static folly::exception_wrapper recv_wrapped_throws_function2(bool& _return, ::apache::thrift::ClientReceiveState& state);
  static bool recv_throws_function2(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual bool recv_instance_throws_function2(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_throws_function2(bool& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void throws_function2T(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, bool param1);
 public:
  virtual void throws_function3(std::unique_ptr<apache::thrift::RequestCallback> callback, bool param1, const ::std::string& param2);
  virtual void throws_function3(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, bool param1, const ::std::string& param2);
 protected:
  void throws_function3Impl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, bool param1, const ::std::string& param2);
 public:
  virtual void sync_throws_function3(::std::map<int32_t, ::std::string>& _return, bool param1, const ::std::string& param2);
  virtual void sync_throws_function3(apache::thrift::RpcOptions& rpcOptions, ::std::map<int32_t, ::std::string>& _return, bool param1, const ::std::string& param2);
  virtual folly::Future<::std::map<int32_t, ::std::string>> future_throws_function3(bool param1, const ::std::string& param2);
  virtual folly::SemiFuture<::std::map<int32_t, ::std::string>> semifuture_throws_function3(bool param1, const ::std::string& param2);
  virtual folly::Future<::std::map<int32_t, ::std::string>> future_throws_function3(apache::thrift::RpcOptions& rpcOptions, bool param1, const ::std::string& param2);
  virtual folly::SemiFuture<::std::map<int32_t, ::std::string>> semifuture_throws_function3(apache::thrift::RpcOptions& rpcOptions, bool param1, const ::std::string& param2);
  virtual folly::Future<std::pair<::std::map<int32_t, ::std::string>, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_throws_function3(apache::thrift::RpcOptions& rpcOptions, bool param1, const ::std::string& param2);
  virtual folly::SemiFuture<std::pair<::std::map<int32_t, ::std::string>, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_throws_function3(apache::thrift::RpcOptions& rpcOptions, bool param1, const ::std::string& param2);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<::std::map<int32_t, ::std::string>> co_throws_function3(bool param1, const ::std::string& param2) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_return co_await folly::coro::detachOnCancel(semifuture_throws_function3(param1, param2));
    } else {
      co_return co_await semifuture_throws_function3(param1, param2);
    }
  }
  template <int = 0>
  folly::coro::Task<::std::map<int32_t, ::std::string>> co_throws_function3(apache::thrift::RpcOptions& rpcOptions, bool param1, const ::std::string& param2) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_return co_await folly::coro::detachOnCancel(semifuture_throws_function3(rpcOptions, param1, param2));
    } else {
      co_return co_await semifuture_throws_function3(rpcOptions, param1, param2);
    }
  }
#endif // FOLLY_HAS_COROUTINES
  virtual void throws_function3(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, bool param1, const ::std::string& param2);
  static folly::exception_wrapper recv_wrapped_throws_function3(::std::map<int32_t, ::std::string>& _return, ::apache::thrift::ClientReceiveState& state);
  static void recv_throws_function3(::std::map<int32_t, ::std::string>& _return, ::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_throws_function3(::std::map<int32_t, ::std::string>& _return, ::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_throws_function3(::std::map<int32_t, ::std::string>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void throws_function3T(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, bool param1, const ::std::string& param2);
 public:
  virtual void oneway_void_ret(std::unique_ptr<apache::thrift::RequestCallback> callback);
  virtual void oneway_void_ret(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback);
 protected:
  void oneway_void_retImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback);
 public:
  virtual void sync_oneway_void_ret();
  virtual void sync_oneway_void_ret(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::Future<folly::Unit> future_oneway_void_ret();
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_void_ret();
  virtual folly::Future<folly::Unit> future_oneway_void_ret(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_void_ret(apache::thrift::RpcOptions& rpcOptions);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<void> co_oneway_void_ret() {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_await folly::coro::detachOnCancel(semifuture_oneway_void_ret());
    } else {
      co_await semifuture_oneway_void_ret();
    }
  }
  template <int = 0>
  folly::coro::Task<void> co_oneway_void_ret(apache::thrift::RpcOptions& rpcOptions) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_await folly::coro::detachOnCancel(semifuture_oneway_void_ret(rpcOptions));
    } else {
      co_await semifuture_oneway_void_ret(rpcOptions);
    }
  }
#endif // FOLLY_HAS_COROUTINES
  virtual void oneway_void_ret(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback);
 private:
  template <typename Protocol_>
  void oneway_void_retT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback);
 public:
  virtual void oneway_void_ret_i32_i32_i32_i32_i32_param(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5);
  virtual void oneway_void_ret_i32_i32_i32_i32_i32_param(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5);
 protected:
  void oneway_void_ret_i32_i32_i32_i32_i32_paramImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5);
 public:
  virtual void sync_oneway_void_ret_i32_i32_i32_i32_i32_param(int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5);
  virtual void sync_oneway_void_ret_i32_i32_i32_i32_i32_param(apache::thrift::RpcOptions& rpcOptions, int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5);
  virtual folly::Future<folly::Unit> future_oneway_void_ret_i32_i32_i32_i32_i32_param(int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_void_ret_i32_i32_i32_i32_i32_param(int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5);
  virtual folly::Future<folly::Unit> future_oneway_void_ret_i32_i32_i32_i32_i32_param(apache::thrift::RpcOptions& rpcOptions, int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_void_ret_i32_i32_i32_i32_i32_param(apache::thrift::RpcOptions& rpcOptions, int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<void> co_oneway_void_ret_i32_i32_i32_i32_i32_param(int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_await folly::coro::detachOnCancel(semifuture_oneway_void_ret_i32_i32_i32_i32_i32_param(param1, param2, param3, param4, param5));
    } else {
      co_await semifuture_oneway_void_ret_i32_i32_i32_i32_i32_param(param1, param2, param3, param4, param5);
    }
  }
  template <int = 0>
  folly::coro::Task<void> co_oneway_void_ret_i32_i32_i32_i32_i32_param(apache::thrift::RpcOptions& rpcOptions, int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_await folly::coro::detachOnCancel(semifuture_oneway_void_ret_i32_i32_i32_i32_i32_param(rpcOptions, param1, param2, param3, param4, param5));
    } else {
      co_await semifuture_oneway_void_ret_i32_i32_i32_i32_i32_param(rpcOptions, param1, param2, param3, param4, param5);
    }
  }
#endif // FOLLY_HAS_COROUTINES
  virtual void oneway_void_ret_i32_i32_i32_i32_i32_param(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5);
 private:
  template <typename Protocol_>
  void oneway_void_ret_i32_i32_i32_i32_i32_paramT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5);
 public:
  virtual void oneway_void_ret_map_setlist_param(std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2);
  virtual void oneway_void_ret_map_setlist_param(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2);
 protected:
  void oneway_void_ret_map_setlist_paramImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2);
 public:
  virtual void sync_oneway_void_ret_map_setlist_param(const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2);
  virtual void sync_oneway_void_ret_map_setlist_param(apache::thrift::RpcOptions& rpcOptions, const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2);
  virtual folly::Future<folly::Unit> future_oneway_void_ret_map_setlist_param(const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_void_ret_map_setlist_param(const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2);
  virtual folly::Future<folly::Unit> future_oneway_void_ret_map_setlist_param(apache::thrift::RpcOptions& rpcOptions, const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_void_ret_map_setlist_param(apache::thrift::RpcOptions& rpcOptions, const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<void> co_oneway_void_ret_map_setlist_param(const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_await folly::coro::detachOnCancel(semifuture_oneway_void_ret_map_setlist_param(param1, param2));
    } else {
      co_await semifuture_oneway_void_ret_map_setlist_param(param1, param2);
    }
  }
  template <int = 0>
  folly::coro::Task<void> co_oneway_void_ret_map_setlist_param(apache::thrift::RpcOptions& rpcOptions, const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_await folly::coro::detachOnCancel(semifuture_oneway_void_ret_map_setlist_param(rpcOptions, param1, param2));
    } else {
      co_await semifuture_oneway_void_ret_map_setlist_param(rpcOptions, param1, param2);
    }
  }
#endif // FOLLY_HAS_COROUTINES
  virtual void oneway_void_ret_map_setlist_param(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2);
 private:
  template <typename Protocol_>
  void oneway_void_ret_map_setlist_paramT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const ::std::map<::std::string, int64_t>& param1, const ::std::set<::std::vector<::std::string>>& param2);
 public:
  virtual void oneway_void_ret_struct_param(std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::some::valid::ns::MyStruct& param1);
  virtual void oneway_void_ret_struct_param(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::some::valid::ns::MyStruct& param1);
 protected:
  void oneway_void_ret_struct_paramImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const  ::some::valid::ns::MyStruct& param1);
 public:
  virtual void sync_oneway_void_ret_struct_param(const  ::some::valid::ns::MyStruct& param1);
  virtual void sync_oneway_void_ret_struct_param(apache::thrift::RpcOptions& rpcOptions, const  ::some::valid::ns::MyStruct& param1);
  virtual folly::Future<folly::Unit> future_oneway_void_ret_struct_param(const  ::some::valid::ns::MyStruct& param1);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_void_ret_struct_param(const  ::some::valid::ns::MyStruct& param1);
  virtual folly::Future<folly::Unit> future_oneway_void_ret_struct_param(apache::thrift::RpcOptions& rpcOptions, const  ::some::valid::ns::MyStruct& param1);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_void_ret_struct_param(apache::thrift::RpcOptions& rpcOptions, const  ::some::valid::ns::MyStruct& param1);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<void> co_oneway_void_ret_struct_param(const  ::some::valid::ns::MyStruct& param1) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_await folly::coro::detachOnCancel(semifuture_oneway_void_ret_struct_param(param1));
    } else {
      co_await semifuture_oneway_void_ret_struct_param(param1);
    }
  }
  template <int = 0>
  folly::coro::Task<void> co_oneway_void_ret_struct_param(apache::thrift::RpcOptions& rpcOptions, const  ::some::valid::ns::MyStruct& param1) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_await folly::coro::detachOnCancel(semifuture_oneway_void_ret_struct_param(rpcOptions, param1));
    } else {
      co_await semifuture_oneway_void_ret_struct_param(rpcOptions, param1);
    }
  }
#endif // FOLLY_HAS_COROUTINES
  virtual void oneway_void_ret_struct_param(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const  ::some::valid::ns::MyStruct& param1);
 private:
  template <typename Protocol_>
  void oneway_void_ret_struct_paramT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const  ::some::valid::ns::MyStruct& param1);
 public:
  virtual void oneway_void_ret_listunion_param(std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::vector< ::some::valid::ns::ComplexUnion>& param1);
  virtual void oneway_void_ret_listunion_param(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::vector< ::some::valid::ns::ComplexUnion>& param1);
 protected:
  void oneway_void_ret_listunion_paramImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const ::std::vector< ::some::valid::ns::ComplexUnion>& param1);
 public:
  virtual void sync_oneway_void_ret_listunion_param(const ::std::vector< ::some::valid::ns::ComplexUnion>& param1);
  virtual void sync_oneway_void_ret_listunion_param(apache::thrift::RpcOptions& rpcOptions, const ::std::vector< ::some::valid::ns::ComplexUnion>& param1);
  virtual folly::Future<folly::Unit> future_oneway_void_ret_listunion_param(const ::std::vector< ::some::valid::ns::ComplexUnion>& param1);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_void_ret_listunion_param(const ::std::vector< ::some::valid::ns::ComplexUnion>& param1);
  virtual folly::Future<folly::Unit> future_oneway_void_ret_listunion_param(apache::thrift::RpcOptions& rpcOptions, const ::std::vector< ::some::valid::ns::ComplexUnion>& param1);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_void_ret_listunion_param(apache::thrift::RpcOptions& rpcOptions, const ::std::vector< ::some::valid::ns::ComplexUnion>& param1);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<void> co_oneway_void_ret_listunion_param(const ::std::vector< ::some::valid::ns::ComplexUnion>& param1) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_await folly::coro::detachOnCancel(semifuture_oneway_void_ret_listunion_param(param1));
    } else {
      co_await semifuture_oneway_void_ret_listunion_param(param1);
    }
  }
  template <int = 0>
  folly::coro::Task<void> co_oneway_void_ret_listunion_param(apache::thrift::RpcOptions& rpcOptions, const ::std::vector< ::some::valid::ns::ComplexUnion>& param1) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_await folly::coro::detachOnCancel(semifuture_oneway_void_ret_listunion_param(rpcOptions, param1));
    } else {
      co_await semifuture_oneway_void_ret_listunion_param(rpcOptions, param1);
    }
  }
#endif // FOLLY_HAS_COROUTINES
  virtual void oneway_void_ret_listunion_param(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const ::std::vector< ::some::valid::ns::ComplexUnion>& param1);
 private:
  template <typename Protocol_>
  void oneway_void_ret_listunion_paramT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const ::std::vector< ::some::valid::ns::ComplexUnion>& param1);
 public:
};

}} // extra::svc
