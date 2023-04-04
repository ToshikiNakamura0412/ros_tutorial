#include <ros/ros.h>
#include <tutorial_msgs/Num.h>

class TestMsgSubscriber
{
public:
    TestMsgSubscriber();
    void process();
private:
    void num_callback(const tutorial_msgs::Num::ConstPtr& msg);
    tutorial_msgs::Num num_;
    ros::NodeHandle   nh_;
    ros::Subscriber   num_sub_;
};

TestMsgSubscriber::TestMsgSubscriber():nh_("")
{
    num_sub_ = nh_.subscribe("/num", 1, &TestMsgSubscriber::num_callback, this);
}

void TestMsgSubscriber::num_callback(const tutorial_msgs::Num::ConstPtr& msg)
{
    num_ = *msg;
    ROS_INFO_STREAM(num_);
}

void TestMsgSubscriber::process()
{
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }
}

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "test_msg_subscriber");
    TestMsgSubscriber test_msg_subscriber;
    test_msg_subscriber.process();

    return 0;
}
