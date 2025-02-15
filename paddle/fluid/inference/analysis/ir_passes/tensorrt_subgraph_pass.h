// Copyright (c) 2018 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "paddle/fluid/framework/ir/fuse_pass_base.h"
#include "paddle/fluid/framework/ir/pass.h"
#include "paddle/fluid/inference/api/paddle_analysis_config.h"

namespace paddle {
namespace framework {
namespace ir {
class Graph;
class Node;
}  // namespace ir
}  // namespace framework
}  // namespace paddle

namespace paddle {
namespace inference {
namespace analysis {

class TensorRtSubgraphPass : public framework::ir::FusePassBase {
 public:
  void ApplyImpl(framework::ir::Graph *graph) const override;

 private:
  std::string CreateTensorRTOp(framework::ir::Node *x,
                               framework::ir::Graph *graph,
                               const std::vector<std::string> &graph_params,
                               std::vector<std::string> *repetitive_params,
                               bool use_cuda_graph) const;
  void CleanIntermediateOutputs(framework::ir::Node *node);
};

}  // namespace analysis
}  // namespace inference
}  // namespace paddle
