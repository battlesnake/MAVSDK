// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see
// https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/custom_action/custom_action.proto)

#include "custom_action/custom_action.grpc.pb.h"
#include "plugins/custom_action/custom_action.h"

#include "mavsdk.h"
#include "lazy_plugin.h"
#include "log.h"
#include <atomic>
#include <cmath>
#include <future>
#include <limits>
#include <memory>
#include <sstream>
#include <vector>

namespace mavsdk {
namespace mavsdk_server {

template<typename CustomAction = CustomAction, typename LazyPlugin = LazyPlugin<CustomAction>>
class CustomActionServiceImpl final : public rpc::custom_action::CustomActionService::Service {
public:
    CustomActionServiceImpl(LazyPlugin& lazy_plugin) : _lazy_plugin(lazy_plugin) {}

    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::CustomAction::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_custom_action_result = new rpc::custom_action::CustomActionResult();
        rpc_custom_action_result->set_result(rpc_result);
        std::stringstream ss;
        ss << result;
        rpc_custom_action_result->set_result_str(ss.str());

        response->set_allocated_custom_action_result(rpc_custom_action_result);
    }

    static std::unique_ptr<rpc::custom_action::ActionToExecute>
    translateToRpcActionToExecute(const mavsdk::CustomAction::ActionToExecute& action_to_execute)
    {
        auto rpc_obj = std::make_unique<rpc::custom_action::ActionToExecute>();

        rpc_obj->set_id(action_to_execute.id);

        rpc_obj->set_timeout(action_to_execute.timeout);

        rpc_obj->set_progress(action_to_execute.progress);

        return rpc_obj;
    }

    static mavsdk::CustomAction::ActionToExecute
    translateFromRpcActionToExecute(const rpc::custom_action::ActionToExecute& action_to_execute)
    {
        mavsdk::CustomAction::ActionToExecute obj;

        obj.id = action_to_execute.id();

        obj.timeout = action_to_execute.timeout();

        obj.progress = action_to_execute.progress();

        return obj;
    }

    static rpc::custom_action::Command::CommandType
    translateToRpcCommandType(const mavsdk::CustomAction::Command::CommandType& command_type)
    {
        switch (command_type) {
            default:
                LogErr() << "Unknown command_type enum value: " << static_cast<int>(command_type);
            // FALLTHROUGH
            case mavsdk::CustomAction::Command::CommandType::Long:
                return rpc::custom_action::Command_CommandType_COMMAND_TYPE_LONG;
            case mavsdk::CustomAction::Command::CommandType::Int:
                return rpc::custom_action::Command_CommandType_COMMAND_TYPE_INT;
        }
    }

    static mavsdk::CustomAction::Command::CommandType
    translateFromRpcCommandType(const rpc::custom_action::Command::CommandType command_type)
    {
        switch (command_type) {
            default:
                LogErr() << "Unknown command_type enum value: " << static_cast<int>(command_type);
            // FALLTHROUGH
            case rpc::custom_action::Command_CommandType_COMMAND_TYPE_LONG:
                return mavsdk::CustomAction::Command::CommandType::Long;
            case rpc::custom_action::Command_CommandType_COMMAND_TYPE_INT:
                return mavsdk::CustomAction::Command::CommandType::Int;
        }
    }

    static std::unique_ptr<rpc::custom_action::Command>
    translateToRpcCommand(const mavsdk::CustomAction::Command& command)
    {
        auto rpc_obj = std::make_unique<rpc::custom_action::Command>();

        rpc_obj->set_type(translateToRpcCommandType(command.type));

        rpc_obj->set_target_system_id(command.target_system_id);

        rpc_obj->set_target_component_id(command.target_component_id);

        rpc_obj->set_frame(command.frame);

        rpc_obj->set_command(command.command);

        rpc_obj->set_param1(command.param1);

        rpc_obj->set_param2(command.param2);

        rpc_obj->set_param3(command.param3);

        rpc_obj->set_param4(command.param4);

        rpc_obj->set_param5(command.param5);

        rpc_obj->set_param6(command.param6);

        rpc_obj->set_param7(command.param7);

        rpc_obj->set_is_local(command.is_local);

        return rpc_obj;
    }

    static mavsdk::CustomAction::Command
    translateFromRpcCommand(const rpc::custom_action::Command& command)
    {
        mavsdk::CustomAction::Command obj;

        obj.type = translateFromRpcCommandType(command.type());

        obj.target_system_id = command.target_system_id();

        obj.target_component_id = command.target_component_id();

        obj.frame = command.frame();

        obj.command = command.command();

        obj.param1 = command.param1();

        obj.param2 = command.param2();

        obj.param3 = command.param3();

        obj.param4 = command.param4();

        obj.param5 = command.param5();

        obj.param6 = command.param6();

        obj.param7 = command.param7();

        obj.is_local = command.is_local();

        return obj;
    }

    static rpc::custom_action::Parameter::ParameterType translateToRpcParameterType(
        const mavsdk::CustomAction::Parameter::ParameterType& parameter_type)
    {
        switch (parameter_type) {
            default:
                LogErr() << "Unknown parameter_type enum value: "
                         << static_cast<int>(parameter_type);
            // FALLTHROUGH
            case mavsdk::CustomAction::Parameter::ParameterType::Int:
                return rpc::custom_action::Parameter_ParameterType_PARAMETER_TYPE_INT;
            case mavsdk::CustomAction::Parameter::ParameterType::Float:
                return rpc::custom_action::Parameter_ParameterType_PARAMETER_TYPE_FLOAT;
        }
    }

    static mavsdk::CustomAction::Parameter::ParameterType
    translateFromRpcParameterType(const rpc::custom_action::Parameter::ParameterType parameter_type)
    {
        switch (parameter_type) {
            default:
                LogErr() << "Unknown parameter_type enum value: "
                         << static_cast<int>(parameter_type);
            // FALLTHROUGH
            case rpc::custom_action::Parameter_ParameterType_PARAMETER_TYPE_INT:
                return mavsdk::CustomAction::Parameter::ParameterType::Int;
            case rpc::custom_action::Parameter_ParameterType_PARAMETER_TYPE_FLOAT:
                return mavsdk::CustomAction::Parameter::ParameterType::Float;
        }
    }

    static std::unique_ptr<rpc::custom_action::Parameter>
    translateToRpcParameter(const mavsdk::CustomAction::Parameter& parameter)
    {
        auto rpc_obj = std::make_unique<rpc::custom_action::Parameter>();

        rpc_obj->set_type(translateToRpcParameterType(parameter.type));

        rpc_obj->set_name(parameter.name);

        rpc_obj->set_value(parameter.value);

        return rpc_obj;
    }

    static mavsdk::CustomAction::Parameter
    translateFromRpcParameter(const rpc::custom_action::Parameter& parameter)
    {
        mavsdk::CustomAction::Parameter obj;

        obj.type = translateFromRpcParameterType(parameter.type());

        obj.name = parameter.name();

        obj.value = parameter.value();

        return obj;
    }

    static rpc::custom_action::Stage::StateTransitionCondition
    translateToRpcStateTransitionCondition(
        const mavsdk::CustomAction::Stage::StateTransitionCondition& state_transition_condition)
    {
        switch (state_transition_condition) {
            default:
                LogErr() << "Unknown state_transition_condition enum value: "
                         << static_cast<int>(state_transition_condition);
            // FALLTHROUGH
            case mavsdk::CustomAction::Stage::StateTransitionCondition::OnResultSuccess:
                return rpc::custom_action::
                    Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_RESULT_SUCCESS;
            case mavsdk::CustomAction::Stage::StateTransitionCondition::OnTimeout:
                return rpc::custom_action::
                    Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_TIMEOUT;
            case mavsdk::CustomAction::Stage::StateTransitionCondition::OnLandingComplete:
                return rpc::custom_action::
                    Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_LANDING_COMPLETE;
            case mavsdk::CustomAction::Stage::StateTransitionCondition::OnTakeoffComplete:
                return rpc::custom_action::
                    Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_TAKEOFF_COMPLETE;
            case mavsdk::CustomAction::Stage::StateTransitionCondition::OnModeChange:
                return rpc::custom_action::
                    Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_MODE_CHANGE;
            case mavsdk::CustomAction::Stage::StateTransitionCondition::OnCustomConditionTrue:
                return rpc::custom_action::
                    Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_CUSTOM_CONDITION_TRUE;
            case mavsdk::CustomAction::Stage::StateTransitionCondition::OnCustomConditionFalse:
                return rpc::custom_action::
                    Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_CUSTOM_CONDITION_FALSE;
        }
    }

    static mavsdk::CustomAction::Stage::StateTransitionCondition
    translateFromRpcStateTransitionCondition(
        const rpc::custom_action::Stage::StateTransitionCondition state_transition_condition)
    {
        switch (state_transition_condition) {
            default:
                LogErr() << "Unknown state_transition_condition enum value: "
                         << static_cast<int>(state_transition_condition);
            // FALLTHROUGH
            case rpc::custom_action::
                Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_RESULT_SUCCESS:
                return mavsdk::CustomAction::Stage::StateTransitionCondition::OnResultSuccess;
            case rpc::custom_action::
                Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_TIMEOUT:
                return mavsdk::CustomAction::Stage::StateTransitionCondition::OnTimeout;
            case rpc::custom_action::
                Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_LANDING_COMPLETE:
                return mavsdk::CustomAction::Stage::StateTransitionCondition::OnLandingComplete;
            case rpc::custom_action::
                Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_TAKEOFF_COMPLETE:
                return mavsdk::CustomAction::Stage::StateTransitionCondition::OnTakeoffComplete;
            case rpc::custom_action::
                Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_MODE_CHANGE:
                return mavsdk::CustomAction::Stage::StateTransitionCondition::OnModeChange;
            case rpc::custom_action::
                Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_CUSTOM_CONDITION_TRUE:
                return mavsdk::CustomAction::Stage::StateTransitionCondition::OnCustomConditionTrue;
            case rpc::custom_action::
                Stage_StateTransitionCondition_STATE_TRANSITION_CONDITION_ON_CUSTOM_CONDITION_FALSE:
                return mavsdk::CustomAction::Stage::StateTransitionCondition::
                    OnCustomConditionFalse;
        }
    }

    static std::unique_ptr<rpc::custom_action::Stage>
    translateToRpcStage(const mavsdk::CustomAction::Stage& stage)
    {
        auto rpc_obj = std::make_unique<rpc::custom_action::Stage>();

        rpc_obj->set_allocated_command(translateToRpcCommand(stage.command).release());

        rpc_obj->set_script(stage.script);

        rpc_obj->set_allocated_parameter_set(
            translateToRpcParameter(stage.parameter_set).release());

        rpc_obj->set_state_transition_condition(
            translateToRpcStateTransitionCondition(stage.state_transition_condition));

        rpc_obj->set_timeout(stage.timeout);

        return rpc_obj;
    }

    static mavsdk::CustomAction::Stage translateFromRpcStage(const rpc::custom_action::Stage& stage)
    {
        mavsdk::CustomAction::Stage obj;

        obj.command = translateFromRpcCommand(stage.command());

        obj.script = stage.script();

        obj.parameter_set = translateFromRpcParameter(stage.parameter_set());

        obj.state_transition_condition =
            translateFromRpcStateTransitionCondition(stage.state_transition_condition());

        obj.timeout = stage.timeout();

        return obj;
    }

    static rpc::custom_action::ActionMetadata::ActionCompleteCondition
    translateToRpcActionCompleteCondition(
        const mavsdk::CustomAction::ActionMetadata::ActionCompleteCondition&
            action_complete_condition)
    {
        switch (action_complete_condition) {
            default:
                LogErr() << "Unknown action_complete_condition enum value: "
                         << static_cast<int>(action_complete_condition);
            // FALLTHROUGH
            case mavsdk::CustomAction::ActionMetadata::ActionCompleteCondition::OnLastStageComplete:
                return rpc::custom_action::
                    ActionMetadata_ActionCompleteCondition_ACTION_COMPLETE_CONDITION_ON_LAST_STAGE_COMPLETE;
            case mavsdk::CustomAction::ActionMetadata::ActionCompleteCondition::OnTimeout:
                return rpc::custom_action::
                    ActionMetadata_ActionCompleteCondition_ACTION_COMPLETE_CONDITION_ON_TIMEOUT;
            case mavsdk::CustomAction::ActionMetadata::ActionCompleteCondition::OnResultSuccess:
                return rpc::custom_action::
                    ActionMetadata_ActionCompleteCondition_ACTION_COMPLETE_CONDITION_ON_RESULT_SUCCESS;
            case mavsdk::CustomAction::ActionMetadata::ActionCompleteCondition::
                OnCustomConditionTrue:
                return rpc::custom_action::
                    ActionMetadata_ActionCompleteCondition_ACTION_COMPLETE_CONDITION_ON_CUSTOM_CONDITION_TRUE;
            case mavsdk::CustomAction::ActionMetadata::ActionCompleteCondition::
                OnCustomConditionFalse:
                return rpc::custom_action::
                    ActionMetadata_ActionCompleteCondition_ACTION_COMPLETE_CONDITION_ON_CUSTOM_CONDITION_FALSE;
        }
    }

    static mavsdk::CustomAction::ActionMetadata::ActionCompleteCondition
    translateFromRpcActionCompleteCondition(
        const rpc::custom_action::ActionMetadata::ActionCompleteCondition action_complete_condition)
    {
        switch (action_complete_condition) {
            default:
                LogErr() << "Unknown action_complete_condition enum value: "
                         << static_cast<int>(action_complete_condition);
            // FALLTHROUGH
            case rpc::custom_action::
                ActionMetadata_ActionCompleteCondition_ACTION_COMPLETE_CONDITION_ON_LAST_STAGE_COMPLETE:
                return mavsdk::CustomAction::ActionMetadata::ActionCompleteCondition::
                    OnLastStageComplete;
            case rpc::custom_action::
                ActionMetadata_ActionCompleteCondition_ACTION_COMPLETE_CONDITION_ON_TIMEOUT:
                return mavsdk::CustomAction::ActionMetadata::ActionCompleteCondition::OnTimeout;
            case rpc::custom_action::
                ActionMetadata_ActionCompleteCondition_ACTION_COMPLETE_CONDITION_ON_RESULT_SUCCESS:
                return mavsdk::CustomAction::ActionMetadata::ActionCompleteCondition::
                    OnResultSuccess;
            case rpc::custom_action::
                ActionMetadata_ActionCompleteCondition_ACTION_COMPLETE_CONDITION_ON_CUSTOM_CONDITION_TRUE:
                return mavsdk::CustomAction::ActionMetadata::ActionCompleteCondition::
                    OnCustomConditionTrue;
            case rpc::custom_action::
                ActionMetadata_ActionCompleteCondition_ACTION_COMPLETE_CONDITION_ON_CUSTOM_CONDITION_FALSE:
                return mavsdk::CustomAction::ActionMetadata::ActionCompleteCondition::
                    OnCustomConditionFalse;
        }
    }

    static std::unique_ptr<rpc::custom_action::ActionMetadata>
    translateToRpcActionMetadata(const mavsdk::CustomAction::ActionMetadata& action_metadata)
    {
        auto rpc_obj = std::make_unique<rpc::custom_action::ActionMetadata>();

        rpc_obj->set_id(action_metadata.id);

        rpc_obj->set_action_name(action_metadata.action_name);

        rpc_obj->set_action_description(action_metadata.action_description);

        rpc_obj->set_global_script(action_metadata.global_script);

        rpc_obj->set_global_timeout(action_metadata.global_timeout);

        rpc_obj->set_action_complete_condition(
            translateToRpcActionCompleteCondition(action_metadata.action_complete_condition));

        for (const auto& elem : action_metadata.stages) {
            auto* ptr = rpc_obj->add_stages();
            ptr->CopyFrom(*translateToRpcStage(elem).release());
        }

        return rpc_obj;
    }

    static mavsdk::CustomAction::ActionMetadata
    translateFromRpcActionMetadata(const rpc::custom_action::ActionMetadata& action_metadata)
    {
        mavsdk::CustomAction::ActionMetadata obj;

        obj.id = action_metadata.id();

        obj.action_name = action_metadata.action_name();

        obj.action_description = action_metadata.action_description();

        obj.global_script = action_metadata.global_script();

        obj.global_timeout = action_metadata.global_timeout();

        obj.action_complete_condition =
            translateFromRpcActionCompleteCondition(action_metadata.action_complete_condition());

        for (const auto& elem : action_metadata.stages()) {
            obj.stages.push_back(
                translateFromRpcStage(static_cast<mavsdk::rpc::custom_action::Stage>(elem)));
        }

        return obj;
    }

    static rpc::custom_action::CustomActionResult::Result
    translateToRpcResult(const mavsdk::CustomAction::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::CustomAction::Result::Unknown:
                return rpc::custom_action::CustomActionResult_Result_RESULT_UNKNOWN;
            case mavsdk::CustomAction::Result::Success:
                return rpc::custom_action::CustomActionResult_Result_RESULT_SUCCESS;
            case mavsdk::CustomAction::Result::Error:
                return rpc::custom_action::CustomActionResult_Result_RESULT_ERROR;
            case mavsdk::CustomAction::Result::Timeout:
                return rpc::custom_action::CustomActionResult_Result_RESULT_TIMEOUT;
            case mavsdk::CustomAction::Result::Unsupported:
                return rpc::custom_action::CustomActionResult_Result_RESULT_UNSUPPORTED;
            case mavsdk::CustomAction::Result::InProgress:
                return rpc::custom_action::CustomActionResult_Result_RESULT_IN_PROGRESS;
        }
    }

    static mavsdk::CustomAction::Result
    translateFromRpcResult(const rpc::custom_action::CustomActionResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::custom_action::CustomActionResult_Result_RESULT_UNKNOWN:
                return mavsdk::CustomAction::Result::Unknown;
            case rpc::custom_action::CustomActionResult_Result_RESULT_SUCCESS:
                return mavsdk::CustomAction::Result::Success;
            case rpc::custom_action::CustomActionResult_Result_RESULT_ERROR:
                return mavsdk::CustomAction::Result::Error;
            case rpc::custom_action::CustomActionResult_Result_RESULT_TIMEOUT:
                return mavsdk::CustomAction::Result::Timeout;
            case rpc::custom_action::CustomActionResult_Result_RESULT_UNSUPPORTED:
                return mavsdk::CustomAction::Result::Unsupported;
            case rpc::custom_action::CustomActionResult_Result_RESULT_IN_PROGRESS:
                return mavsdk::CustomAction::Result::InProgress;
        }
    }

    grpc::Status SetCustomAction(
        grpc::ServerContext* /* context */,
        const rpc::custom_action::SetCustomActionRequest* request,
        rpc::custom_action::SetCustomActionResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::CustomAction::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "SetCustomAction sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->set_custom_action(
            translateFromRpcActionToExecute(request->action_to_execute()));

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status SubscribeCustomAction(
        grpc::ServerContext* /* context */,
        const mavsdk::rpc::custom_action::SubscribeCustomActionRequest* /* request */,
        grpc::ServerWriter<rpc::custom_action::CustomActionResponse>* writer) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            return grpc::Status::OK;
        }

        auto stream_closed_promise = std::make_shared<std::promise<void>>();
        auto stream_closed_future = stream_closed_promise->get_future();
        register_stream_stop_promise(stream_closed_promise);

        auto is_finished = std::make_shared<bool>(false);
        auto subscribe_mutex = std::make_shared<std::mutex>();

        _lazy_plugin.maybe_plugin()->subscribe_custom_action(
            [this, &writer, &stream_closed_promise, is_finished, subscribe_mutex](
                const mavsdk::CustomAction::ActionToExecute custom_action) {
                rpc::custom_action::CustomActionResponse rpc_response;

                rpc_response.set_allocated_action_to_execute(
                    translateToRpcActionToExecute(custom_action).release());

                std::unique_lock<std::mutex> lock(*subscribe_mutex);
                if (!*is_finished && !writer->Write(rpc_response)) {
                    _lazy_plugin.maybe_plugin()->subscribe_custom_action(nullptr);

                    *is_finished = true;
                    unregister_stream_stop_promise(stream_closed_promise);
                    stream_closed_promise->set_value();
                }
            });

        stream_closed_future.wait();
        std::unique_lock<std::mutex> lock(*subscribe_mutex);
        *is_finished = true;

        return grpc::Status::OK;
    }

    grpc::Status SubscribeCustomActionCancellation(
        grpc::ServerContext* /* context */,
        const mavsdk::rpc::custom_action::SubscribeCustomActionCancellationRequest* /* request */,
        grpc::ServerWriter<rpc::custom_action::CustomActionCancellationResponse>* writer) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            return grpc::Status::OK;
        }

        auto stream_closed_promise = std::make_shared<std::promise<void>>();
        auto stream_closed_future = stream_closed_promise->get_future();
        register_stream_stop_promise(stream_closed_promise);

        auto is_finished = std::make_shared<bool>(false);
        auto subscribe_mutex = std::make_shared<std::mutex>();

        _lazy_plugin.maybe_plugin()->subscribe_custom_action_cancellation(
            [this, &writer, &stream_closed_promise, is_finished, subscribe_mutex](
                const bool custom_action_cancellation) {
                rpc::custom_action::CustomActionCancellationResponse rpc_response;

                rpc_response.set_cancel(custom_action_cancellation);

                std::unique_lock<std::mutex> lock(*subscribe_mutex);
                if (!*is_finished && !writer->Write(rpc_response)) {
                    _lazy_plugin.maybe_plugin()->subscribe_custom_action_cancellation(nullptr);

                    *is_finished = true;
                    unregister_stream_stop_promise(stream_closed_promise);
                    stream_closed_promise->set_value();
                }
            });

        stream_closed_future.wait();
        std::unique_lock<std::mutex> lock(*subscribe_mutex);
        *is_finished = true;

        return grpc::Status::OK;
    }

    grpc::Status RespondCustomAction(
        grpc::ServerContext* /* context */,
        const rpc::custom_action::RespondCustomActionRequest* request,
        rpc::custom_action::RespondCustomActionResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::CustomAction::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "RespondCustomAction sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->respond_custom_action(
            translateFromRpcActionToExecute(request->action_to_execute()),
            translateFromRpcCustomActionResult(request->custom_action_result()));

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status CustomActionMetadata(
        grpc::ServerContext* /* context */,
        const rpc::custom_action::CustomActionMetadataRequest* request,
        rpc::custom_action::CustomActionMetadataResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::CustomAction::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "CustomActionMetadata sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->custom_action_metadata(
            translateFromRpcActionToExecute(request->action_to_execute()), request->file_path());

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);

            response->set_allocated_action_metadata(
                translateToRpcActionMetadata(result.second).release());
        }

        return grpc::Status::OK;
    }

    grpc::Status ExecuteCustomActionStage(
        grpc::ServerContext* /* context */,
        const rpc::custom_action::ExecuteCustomActionStageRequest* request,
        rpc::custom_action::ExecuteCustomActionStageResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::CustomAction::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "ExecuteCustomActionStage sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->execute_custom_action_stage(
            translateFromRpcStage(request->stage()));

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status ExecuteCustomActionGlobalScript(
        grpc::ServerContext* /* context */,
        const rpc::custom_action::ExecuteCustomActionGlobalScriptRequest* request,
        rpc::custom_action::ExecuteCustomActionGlobalScriptResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::CustomAction::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "ExecuteCustomActionGlobalScript sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->execute_custom_action_global_script(
            request->global_script());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    void stop()
    {
        _stopped.store(true);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom)
    {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom)
    {
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end();
             /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }

    LazyPlugin& _lazy_plugin;
    std::atomic<bool> _stopped{false};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises{};
};

} // namespace mavsdk_server
} // namespace mavsdk