from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package = 'barbatos_demo',
            executable = 'publisher',
            name = 'barbatos_publisher',
            parameters=[{'publish_rate_ms': 10}]
            ),
        Node(
            package = 'barbatos_demo',
            executable = 'subscriber',
            name = 'barbatos_subscriber',
            output = 'screen'
            ),
        ])

