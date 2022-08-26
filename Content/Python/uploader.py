import unreal
import unreal.GRABBPLibrary as grab
import os
import boto3

session = boto3.session.Session()
client = session.client('s3',
                        region_name='sgp1',
                        endpoint_url='https://sgp1.digitaloceanspaces.com',
                        aws_access_key_id=grab.get_api_key(),
                        aws_secret_access_key=grab.get_api_secret())

# Upload a file to bucket at path
def upload_asset_previews(name:str, path:str):
        
    local_path = unreal.Paths.combine([unreal.Paths.project_saved_dir(), 'Renders', name])
    thumbnail_local_path = unreal.Paths.combine([local_path, name+'.jpeg'])
    video_local_path = unreal.Paths.combine([local_path, name+'.mp4'])

    # Strip path of the `/Game/` prefix
    path = path.replace('/Game/', '')

    # URL keys
    thumbnail_key = path + '/' + name + '.jpeg'
    video_key = path + '/' + name + '.mp4'

    # Upload thumbnail
    with open(thumbnail_local_path, "rb") as img:
        client.put_object(
                            Bucket='grab-bucket',
                            Key=thumbnail_key,
                            Body=img,
                            ACL='public-read'
                        )

    # Upload video
    with open(video_local_path, "rb") as vid:
        client.put_object(
                            Bucket='grab-bucket',
                            Key=video_key,
                            Body=vid,
                            ACL='public-read'
                        )

    thumbnail_url = 'https://grab-bucket.sgp1.digitaloceanspaces.com'+'/'+thumbnail_key
    video_url = 'https://grab-bucket.sgp1.digitaloceanspaces.com'+'/'+video_key

    return thumbnail_url, video_url