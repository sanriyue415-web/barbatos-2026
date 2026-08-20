from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package = 'barbatos_demo',
            executable = 'publisher',
            name = 'barbatos_publisher',
            parameters=[{'publish_rate_ms': 1000}]
            ),
        Node(
            package = 'barbatos_demo',
            executable = 'subscriber',
            name = 'barbatos_subscriber',
            output = 'screen'
            ),
        Node(
            package = "barbatos_demo",
            executable = "marker_publisher",
            name = "barbatos_marker"
            ),
        Node(
            package = "tf2_ros",
            executable = "static_transform_publisher",
            name = "tf2",
            arguments = ['--frame-id','world','--child-frame-id','barbatos_base']
            ),
        Node(
            package = "rviz2",
            executable = "rviz2",
            name = "rviz2"
            )
        ])

