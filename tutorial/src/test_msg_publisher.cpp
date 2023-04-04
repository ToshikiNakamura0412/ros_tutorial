#include <ros/ros.h>
#include <tutorial_msgs/Num.h>

class TestMsgPublisher
{
public:
    TestMsgPublisher();
    void process();
private:
    void pub();
    tutorial_msgs::Num num_;
    ros::NodeHandle   nh_;
    ros::Publisher    num_pub_;
};

TestMsgPublisher::TestMsgPublisher()
{
    num_pub_ = nh_.advertise<tutorial_msgs::Num>("/num", 1);
}

void TestMsgPublisher::pub()
{
    num_.num = 123;
    num_pub_.publish(num_);
}

void TestMsgPublisher::process()
{
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        pub();
        ros::spinOnce();
        loop_rate.sleep();
    }
}

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "test_msg_publisher");
    TestMsgPublisher test_msg_publisher;
    test_msg_publisher.process();

    return 0;
}
