import unreal
import os
import boto3

session = boto3.session.Session()
client = session.client('s3',
                        region_name=unreal.GRABBPLibrary.get_bucket_region(),
                        endpoint_url=unreal.GRABBPLibrary.get_storage_endpoint(),
                        aws_access_key_id=unreal.GRABBPLibrary.get_api_key(),
                        aws_secret_access_key=unreal.GRABBPLibrary.get_api_secret())

# Upload a file to bucket at path
def upload_asset_previews(name:str, path:str):
        
    local_path = unreal.Paths.combine([unreal.Paths.project_saved_dir(), 'Renders', name])
    thumbnail_local_path = unreal.Paths.combine([local_path, name+'.jpeg'])
    video_local_path = unreal.Paths.combine([local_path, name+'.mp4'])

    # Strip path of the `/Game/` prefix
    key_path = path.replace('/Game/', '')

    # URL keys
    thumbnail_key = key_path + '/' + name + '.jpeg'
    video_key = key_path + '/' + name + '.mp4'

    # Upload thumbnail
    with open(thumbnail_local_path, "rb") as img:
        client.put_object(
                            Bucket=unreal.GRABBPLibrary.get_bucket_name(),
                            Key=thumbnail_key,
                            Body=img,
                            ACL='public-read'
                        )

    # Upload video
    with open(video_local_path, "rb") as vid:
        client.put_object(
                            Bucket=unreal.GRABBPLibrary.get_bucket_name(),
                            Key=video_key,
                            Body=vid,
                            ACL='public-read'
                        )

    thumbnail_url = unreal.GRABBPLibrary.get_bucket_url()+'/'+thumbnail_key
    video_url = unreal.GRABBPLibrary.get_bucket_url()+'/'+video_key

    return thumbnail_url, video_url