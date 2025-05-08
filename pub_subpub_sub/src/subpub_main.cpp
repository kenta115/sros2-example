// Copyright 2016 Open Source Robotics Foundation, Inc.
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

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MinimalForwarder : public rclcpp::Node
{
public:
  MinimalForwarder()
  : Node("minimal_forwarder")
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("forwarded_topic", 10);
    auto topic_callback =
      [this](std_msgs::msg::String::UniquePtr msg) -> void {
        auto forwarding_message = std_msgs::msg::String();
        forwarding_message.data = "Fwd: " + msg->data;
        this->publisher_->publish(forwarding_message);
        RCLCPP_INFO(this->get_logger(), "I forwared: '%s'", forwarding_message.data.c_str());
      };
    subscription_ =
      this->create_subscription<std_msgs::msg::String>("topic", 10, topic_callback);
  }

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalForwarder>());
  rclcpp::shutdown();
  return 0;
}
